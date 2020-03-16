#include "krpch.hpp"

#include "BaseAbilities.hpp"

// We set everything to zero, since they are going to change depending on class and level.
BaseAbilities::BaseAbilities(ClassEnum cclass, int level)
    : m_base_attack{0}, m_base_save{{{"FORT", 0}, {"REF", 0}, {"WILL", 0}}}
{
    setBaseAttackBonus(cclass, level);
    setBaseSaveBonus(cclass, level);
}

// Base attack comes in high, medium and low flavors, depending on the class.
// The formula is:
// High: level of class.
// Medium: level of class / ( 3 / 4 ) rounded down.
// Low: level of class / 2 rounded down.
auto BaseAbilities::setBaseAttackBonus(const ClassEnum cclass, const int level) -> void
{
    switch(cclass)
    {
    case ClassEnum::BARBARIAN:
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
    case ClassEnum::RANGER: m_base_attack = level; break;
    case ClassEnum::BARD:
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::ROGUE:
        m_base_attack =
            std::floor(static_cast<double>(level) / (consts::saves::form3 / consts::saves::form4));
        break;
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
    default: m_base_attack = std::floor(static_cast<double>(level) / consts::saves::form2); break;
    }
}

// Base saves are calculated according to class and level. For the formula, refer to the appropriate
// function. Whether a class has high or low saves is explained in the Players Handbook.
auto BaseAbilities::setBaseSaveBonus(const ClassEnum cclass, const int level) -> void
{
    switch(cclass)
    {
    case ClassEnum::BARBARIAN:
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::BARD:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::MONK:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::RANGER:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::ROGUE:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveHigh(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
        m_base_save.at(static_cast<int>(SavesEnum::FORT)).second = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::REF)).second  = calculateBaseSaveLow(level);
        m_base_save.at(static_cast<int>(SavesEnum::WILL)).second = calculateBaseSaveHigh(level);
        break;
    }
}

auto BaseAbilities::getBaseAttackBonus() const -> int
{
    return m_base_attack;
}

auto BaseAbilities::getBaseSaveBonus() const -> ArrayOfPairs
{
    return m_base_save;
}

auto BaseAbilities::getOneSave(int position) const -> std::pair<std::string, int>
{
    return m_base_save.at(position);
}

// The formula for high base saves is level / 2 + 2 rounded down.
auto BaseAbilities::calculateBaseSaveHigh(const int level) -> int
{
    return static_cast<int>(std::floor(static_cast<double>(level) / consts::saves::form2) +
                            consts::saves::form2);
}

// The formula for low base saves is level / 2 rounded down.
auto BaseAbilities::calculateBaseSaveLow(const int level) -> int
{
    return static_cast<int>(std::floor(calculateBaseSaveHigh(level) / consts::saves::form2));
}
