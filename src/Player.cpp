#include "Player.hpp"
#include <string_view>

Player::Player(std::vector<std::string_view> list_race, std::vector<std::string_view> list_class)
    : Creature(list_race, list_class)
{
}
