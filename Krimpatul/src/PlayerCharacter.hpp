#ifndef PLAYERCHARACTER_HPP
#define PLAYERCHARACTER_HPP

#include "BaseCharacter.hpp"

class PlayerCharacter : public BaseCharacter
{
public:
    PlayerCharacter(std::string name = "Unset");
    ~PlayerCharacter(){};

private:
    std::string m_name;
};

#endif
