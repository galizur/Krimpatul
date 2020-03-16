#include "BaseCharacter.hpp"
#include "Enumerators.hpp"
#include "krpch.hpp"

#include "PlayerCharacter.hpp"
#include <string>

PlayerCharacter::PlayerCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align)
    : BaseCharacter(race, cclass, align)
{
}

PlayerCharacter::PlayerCharacter(RaceEnum race, ClassEnum cclass, AlignEnum align,
                                 std::string char_name, std::string player_name)
    : BaseCharacter{race, cclass, align}, m_name_char{std::move(char_name)},
      m_name_player{std::move(player_name)}
{
}

auto PlayerCharacter::setNameChar(const std::string name_char) -> void
{
    m_name_char = name_char;
}

auto PlayerCharacter::setNamePlayer(const std::string name_player) -> void
{
    m_name_player = name_player;
}

auto PlayerCharacter::getNameChar() const -> std::string
{
    return m_name_char;
}

auto PlayerCharacter::getNamePlayer() const -> std::string
{
    return m_name_player;
}
