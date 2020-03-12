#include "krpch.hpp"

#include "BaseCharacter.hpp"

BaseCharacter::BaseCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : m_level{1}, Race{race}, CClass{cclass}, Alignment{align},
      m_abilities{race}, m_hitpoints{cclass, m_abilities.getAbilityMod("CON")},
      m_base_abilities{cclass, m_level}
{
}
