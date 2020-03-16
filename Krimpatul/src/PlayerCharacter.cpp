#include "krpch.hpp"

#include "PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align,
                                 std::string char_name, std::string player_name)
    : BaseCharacter{race, cclass, align}, m_name_char{std::move(char_name)},
      m_name_player{std::move(player_name)}
{
}
