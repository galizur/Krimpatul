#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <array>
#include <string_view>
#include <unordered_map>

namespace constants
{
    using UMapStringInt = std::unordered_map<std::string_view, int>;

    inline constexpr int race_count{9};
    inline constexpr int race_sub_count{9};
    inline constexpr int class_count{12};

    template<int SIZE> using StringArray = std::array<std::string_view, SIZE>;

    inline constexpr StringArray<race_count> c_race_list{"Dwarf",    "Dragonborn", "Elf",
                                                         "Gnome",    "Halfling",   "Half-Elf",
                                                         "Half-Orc", "Human",      "Tiefling"};

    inline constexpr StringArray<race_sub_count> c_race_sub_list{
        "Hill Dwarf",   "Mountain Dwarf", "Dark Elf",           "High Elf",      "Wood Elf",
        "Forest Gnome", "Rock Gnome",     "Lightfoot Halfling", "Stout Halfling"};

    inline constexpr StringArray<class_count> c_class_list{
        "Barbarian", "Bard",   "Cleric", "Druid",    "Fighter", "Monk",
        "Paladin",   "Ranger", "Rogue",  "Sorcerer", "Warlock", "Wizard"};

    const UMapStringInt c_abilities_base{{"Strength", 8},     {"Dexterity", 8}, {"Constitution", 8},
                                         {"Intelligence", 8}, {"Wisdom", 8},    {"Charisma", 8}};

}    // namespace constants

#endif
