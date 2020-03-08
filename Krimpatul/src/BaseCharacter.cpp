#include "krpch.hpp"

#include "BaseCharacter.hpp"

BaseCharacter::BaseCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : Race{race}, CClass{cclass}, Alignment{align},
      m_hitpoints{cclass, getAbilityMod(m_abilities.find("CON")->second)}
{
}

auto BaseCharacter::getAbilityMod(const unsigned short ability) -> short
{
    return ceil((ability - 10 - 1) / 2.0);
}
