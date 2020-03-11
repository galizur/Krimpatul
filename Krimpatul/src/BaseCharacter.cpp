#include "krpch.hpp"

#include "BaseCharacter.hpp"

BaseCharacter::BaseCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : Race{race}, CClass{cclass}, Alignment{align}, m_abilities{race},
      m_hitpoints{cclass, m_abilities.getAbilityMod("CON")}
{
}
