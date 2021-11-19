#include <iostream>

#include "Constants.hpp"
#include "Player.hpp"

auto main() -> int
{
    for(auto i : constants::c_race_list) { std::cout << i << '\n'; }
    int choice{-1};
    std::cin >> choice;

    std::vector<std::string_view> list{constants::c_race_list.at(choice).data()};

    if(choice == 0 || choice == 2 || choice == 3 || choice == 4)
    {
        for(auto i : constants::c_race_sub_list) { std::cout << i << '\n'; }
        std::cin >> choice;
        list.emplace_back(constants::c_race_sub_list.at(choice).data());
    }

    for(auto i : constants::c_class_list) { std::cout << i << '\n'; }
    std::cin >> choice;

    std::vector<std::string_view> list2{constants::c_class_list.at(choice).data()};

    Player pl{list, list2};

    std::cout << pl << '\n';

    return 0;
}
