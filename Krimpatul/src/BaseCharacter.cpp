#include "Constants.hpp"
#include "Enumerators.hpp"
#include "krpch.hpp"

#include "BaseCharacter.hpp"

// Initialization of our creatute. A creature consists of a race, a class and an alignment.
BaseCharacter::BaseCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : Race{race}, CClass{cclass}, Alignment{align}, m_abilities{race}, m_base_abilities{cclass},
      m_hitpoints{cclass, m_abilities.getAbilityMod(static_cast<int>(AbilitiesEnum::CON))},
      m_saves{{{"FORT", consts::saves::base},
               {"REF", consts::saves::base},
               {"WILL", consts::saves::base}}}
{
}

// Attack bonus is how much of a chance there is to hit. It consists of the base attack bonus, the
// strength modifier, the size and extra, such as the enhancment of a magic weapon.
auto BaseCharacter::setAttackBonusMelee(const BaseAbilities bab, const Abilities str,
                                        const Race size, const int misc) -> void
{
    m_attack_bonus_melee = bab.getBaseAttackBonus() +
                           str.getAbilityMod(static_cast<int>(AbilitiesEnum::STR)) +
                           size.getSizeMod() + misc;
}

// The same is for the ranged attack bonus, but instead of strength we use dexterity and there is
// also a penalty incured by the used weapons maximum range.
auto BaseCharacter::setAttackBonusRanged(const BaseAbilities bab, const Abilities dex,
                                         const Race size, const int penalty, const int misc) -> void
{
    m_attack_bonus_ranged = bab.getBaseAttackBonus() +
                            dex.getAbilityMod(static_cast<int>(AbilitiesEnum::DEX)) +
                            size.getSizeMod() + misc - penalty;
}

auto BaseCharacter::getAttackBonusMelee() const -> int
{
    return m_attack_bonus_melee;
}

auto BaseCharacter::getAttackBonusRanged() const -> int
{
    return m_attack_bonus_ranged;
}

// Sets the saves according to the index we pass. The values of the array myst be mapped according
// to specific values (FORT, REF, WILL).
auto BaseCharacter::setSaves(const std::array<int, consts::saves::count> values) -> void
{
    for(std::size_t i = 0; i < values.size(); ++i) { setOneSave(i, values.at(i)); }
}

auto BaseCharacter::setOneSave(const int position, const int value) -> void
{
    switch(position)
    {
    case 0:
        m_saves.at(position).second =
            m_abilities.getAbilityMod(static_cast<int>(AbilitiesEnum::CON)) + value;
        break;
    case 1:
        m_saves.at(position).second =
            m_abilities.getAbilityMod(static_cast<int>(AbilitiesEnum::DEX)) + value;
        break;
    case 2:
        m_saves.at(position).second =
            m_abilities.getAbilityMod(static_cast<int>(AbilitiesEnum::WIS)) + value;
        break;
    }
}

auto BaseCharacter::getSaves() const -> ArrayOfPairs
{
    return m_saves;
}

auto BaseCharacter::getOneSave(const int position) const -> int
{
    return m_saves.at(position).second;
}

auto BaseCharacter::setSpellResistance(const int sr) -> void
{
    m_spell_resistance = sr;
}

auto BaseCharacter::getSpellResistance() const -> int
{
    return m_spell_resistance;
}

auto BaseCharacter::setInitiative(const int dex_mod, const int misc) -> void
{
    m_initiative = dex_mod + misc;
}

auto BaseCharacter::getInitiative() const -> int
{
    return m_initiative;
}

auto BaseCharacter::setGrapple(const int bab, const int str_mod, const int size_mod, const int misc)
    -> void
{
    m_grapple = bab + str_mod + size_mod + misc;
}

auto BaseCharacter::getGrapple() const -> int
{
    return m_grapple;
}

auto BaseCharacter::setArmorClass(const int armor, const int shield, const int dex_mod,
                                  const int size_mod, const int nat_armor, const int defl_mod,
                                  const int misc) -> void
{
    m_armor_class =
        consts::armor::base + armor + shield + dex_mod + size_mod + nat_armor + defl_mod + misc;
}

auto BaseCharacter::setArmorTouch(const int dex_mod, const int size_mod, const int defl_mod,
                                  const int misc) -> void
{
    m_armor_touch = consts::armor::base + dex_mod + size_mod + defl_mod + misc;
}

auto BaseCharacter::setArmorFlat(const int armor, const int shield, const int size_mod,
                                 const int nat_armor, const int defl_mod, const int misc) -> void
{
    m_armor_flat = consts::armor::base + armor + shield + size_mod + nat_armor + defl_mod + misc;
}

auto BaseCharacter::getArmorClass() const -> int
{
    return m_armor_class;
}

auto BaseCharacter::getArmorTouch() const -> int
{
    return m_armor_touch;
}

auto BaseCharacter::getArmorFlat() const -> int
{
    return m_armor_flat;
}

auto BaseCharacter::setSpeed(const RaceEnum race, const std::string armor_rating) -> void
{
    switch(race)
    {
    case RaceEnum::DWARF: m_speed = 20; break;
    case RaceEnum::GNOME:
    case RaceEnum::HALFLING:
    {
        if(armor_rating == "None" || armor_rating == "Light")
        {
            m_speed = 20;
        }
        else
        {
            m_speed = 15;
        }
        break;
    }
    case RaceEnum::HALF_ELF:
    case RaceEnum::ELF:
    case RaceEnum::HUMAN:
    case RaceEnum::HALF_ORC:
    default:
        if(armor_rating == "None" || armor_rating == "Light")
        {
            m_speed = 30;
        }
        else
        {
            m_speed = 20;
        }
        break;
    }
}

auto BaseCharacter::getSpeed() const -> int
{
    return m_speed;
}
