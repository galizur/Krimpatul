#include "krpch.hpp"

#include "PlayerCharacter.hpp"

// To be deleted
#include <iostream>

auto main() -> int
{
    PlayerCharacter player;
    std::cout << player.classesToString(player.getClasses()) << '\n';
    return 0;
}