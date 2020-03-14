#include "krpch.hpp"

#include "BaseAbilities.hpp"

BaseAbilities::BaseAbilities(ClassEnum cclass, unsigned short level)
    : m_base_attack{0}, m_base_save{{"FORT", 0}, {"REF", 0}, {"WILL", 0}}
{
    setBaseAttackBonus(cclass, level);
    setBaseSaveBonus(cclass, level);
}

auto BaseAbilities::setBaseAttackBonus(const ClassEnum      cclass,
                                       const unsigned short level) -> void
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
        m_base_attack = std::floor(static_cast<double>(level) / (3 / 4));
        break;
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
    default:
        m_base_attack = std::floor(static_cast<double>(level) / (3 / 4));
        break;
    }
}

auto BaseAbilities::setBaseSaveBonus(const ClassEnum      cclass,
                                     const unsigned short level) -> void
{
    switch(cclass)
    {
    case ClassEnum::BARBARIAN:
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
        m_base_save.find("FORT")->second = calculateBaseSaveHigh(level);
        m_base_save.find("REF")->second  = calculateBaseSaveLow(level);
        m_base_save.find("WILL")->second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::BARD:
        m_base_save.find("FORT")->second = calculateBaseSaveLow(level);
        m_base_save.find("REF")->second  = calculateBaseSaveHigh(level);
        m_base_save.find("WILL")->second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
        m_base_save.find("FORT")->second = calculateBaseSaveHigh(level);
        m_base_save.find("REF")->second  = calculateBaseSaveLow(level);
        m_base_save.find("WILL")->second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::MONK:
        m_base_save.find("FORT")->second = calculateBaseSaveHigh(level);
        m_base_save.find("REF")->second  = calculateBaseSaveHigh(level);
        m_base_save.find("WILL")->second = calculateBaseSaveHigh(level);
        break;
    case ClassEnum::RANGER:
        m_base_save.find("FORT")->second = calculateBaseSaveHigh(level);
        m_base_save.find("REF")->second  = calculateBaseSaveHigh(level);
        m_base_save.find("WILL")->second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::ROGUE:
        m_base_save.find("FORT")->second = calculateBaseSaveLow(level);
        m_base_save.find("REF")->second  = calculateBaseSaveHigh(level);
        m_base_save.find("WILL")->second = calculateBaseSaveLow(level);
        break;
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
        m_base_save.find("FORT")->second = calculateBaseSaveLow(level);
        m_base_save.find("REF")->second  = calculateBaseSaveLow(level);
        m_base_save.find("WILL")->second = calculateBaseSaveHigh(level);
        break;
    }
}

auto BaseAbilities::getBaseAttackBonus() const -> unsigned short
{
    return m_base_attack;
}

auto BaseAbilities::getBaseSaveBonus() const
    -> std::map<std::string, unsigned short>
{
    return m_base_save;
}

auto BaseAbilities::getOneSave(const std::string value) const
    -> std::pair<std::string, unsigned short>
{
    return std::make_pair(m_base_save.find(value)->first,
                          m_base_save.find(value)->second);
}

auto BaseAbilities::calculateBaseSaveHigh(const unsigned short level)
    -> unsigned short
{
    return static_cast<unsigned short>(
        std::floor(static_cast<double>(level) / 2) + 2);
}

auto BaseAbilities::calculateBaseSaveLow(const unsigned short level)
    -> unsigned short
{
    return static_cast<unsigned short>(
        std::floor(calculateBaseSaveHigh(level) / 2));
}
