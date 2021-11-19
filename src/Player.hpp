#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Creature.hpp"
#include <string_view>

class Player : public Creature
{
private:
public:
    Player(std::vector<std::string_view> /*list_race*/,
           std::vector<std::string_view> = std::vector<std::string_view>{"NOT_SET"} /*list_class*/);
};

#endif
