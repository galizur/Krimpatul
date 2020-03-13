#include "krpch.hpp"

#include "BaseCharacter.hpp"

BaseCharacter::BaseCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : m_level{1}, Race{race}, CClass{cclass}, Alignment{align},
      m_abilities{race}, m_hitpoints{cclass, m_abilities.getAbilityMod("CON")},
      m_base_abilities{cclass, m_level}
{
}

auto BaseCharacter::setAttackBonusMelee(const BaseAbilities bab,
                                        const Abilities str, const Race size)
    -> void
{
    m_attack_bonus_melee = bab.getBaseAttackBonus() +
                           str.getOneAbility("STR").second + size.getSizeMod();
}

auto BaseCharacter::setAttackBonusRanged(const BaseAbilities bab,
                                         const Abilities dex, const Race size,
                                         const short penalty) -> void
{
    m_attack_bonus_ranged = bab.getBaseAttackBonus() +
                            dex.getOneAbility("DEX").second +
                            size.getSizeMod() - penalty;
}

auto BaseCharacter::getAttackBonusMelee() const -> int
{
    return m_attack_bonus_melee;
}

auto BaseCharacter::getAttackBonusRanged() const -> int
{
    return m_attack_bonus_ranged;
}
