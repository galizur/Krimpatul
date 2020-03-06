#ifndef PLAYER_CHARACTER_HPP_
#define PLAYER_CHARACTER_HPP_

#include "BaseCharacter.hpp"

class PlayerCharacter :
    public BaseCharacter
{
public:
    PlayerCharacter() = default;
    ~PlayerCharacter() = default;
private:
    std::string m_name_character{ "Unset" };
    std::string m_name_player{ "Unset" };
    unsigned int m_experience{ 0 };
};

#endif // !PLAYER_CHARACTER_HPP_
