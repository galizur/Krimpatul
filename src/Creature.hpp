#ifndef CREATURE_HPP_
#define CREATURE_HPP_

#include "Constants.hpp"
#include "Race.hpp"
#include "Class.hpp"

#include <string_view>
#include <unordered_map>

class Creature
{
private:
    Race                     m_race;
    Cclass                   m_class;
    constants::UMapStringInt m_abilities{constants::c_abilities_base};

    auto init() -> void;

public:
    Creature(std::vector<std::string_view> /*list_race*/,
             std::vector<std::string_view> /*list_class*/);

    friend auto operator<<(std::ostream & /*out*/, const Creature & /*creature*/) -> std::ostream &;
};

#endif
