#include "krpch.hpp"

#include "Abilities.hpp"

// First we have to set the abilities to their base number (8). Then we can modify them according to
// the race of the creature.
Abilities::Abilities(RaceEnum race)
    : m_abilities{{{"STR", consts::abils::base},
                   {"DEX", consts::abils::base},
                   {"CON", consts::abils::base},
                   {"INT", consts::abils::base},
                   {"WIS", consts::abils::base},
                   {"CHA", consts::abils::base}}}
{
    setRacialAdjustment(race);
}

auto Abilities::setOneAbility(const int position, int value) -> void
{
    m_abilities.at(position).second = value;
}

// Sets the abilities according to the array we pass. The values of the array must be mapped
// according to specific values (STR, DEX, CON, INT, WIS, CHA).
auto Abilities::setAbilities(const std::array<int, consts::abils::count> values) -> void
{
    for(std::size_t i = 0; i < values.size(); ++i) { m_abilities.at(i).second = values.at(i); }
}

auto Abilities::getOneAbility(const int position) const -> std::pair<std::string, int>
{
    return m_abilities.at(position);
}

auto Abilities::getAbilities() const
    -> std::array<std::pair<std::string, int>, consts::abils::count>
{
    return m_abilities;
}

// The formula to get an Ability modifier is: (Ability - 10) / 2 rounded up.
auto Abilities::getAbilityMod(int position) const -> int
{
    return std::ceil((m_abilities.at(position).second - consts::abils::form10) /
                     consts::abils::form2);
}

auto Abilities::resetAbilities(const RaceEnum race) -> void
{
    for(auto x : m_abilities) { x.second = consts::abils::base; }
    setRacialAdjustment(race);
}

// The racial adjustments is set according to a table in the Players Handbook.
auto Abilities::setRacialAdjustment(const RaceEnum race) -> void
{
    switch(race)
    {
    case RaceEnum::DWARF:
        m_abilities.at(static_cast<int>(AbilitiesEnum::CON)).second += consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::CHA)).second -= consts::abils::racial;
        break;
    case RaceEnum::ELF:
        m_abilities.at(static_cast<int>(AbilitiesEnum::DEX)).second += consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::CON)).second -= consts::abils::racial;
        break;
    case RaceEnum::GNOME:
        m_abilities.at(static_cast<int>(AbilitiesEnum::CON)).second += consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::STR)).second -= consts::abils::racial;
        break;
    case RaceEnum::HALF_ORC:
        m_abilities.at(static_cast<int>(AbilitiesEnum::STR)).second += consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::INT)).second -= consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::CHA)).second -= consts::abils::racial;
        break;
    case RaceEnum::HALFLING:
        m_abilities.at(static_cast<int>(AbilitiesEnum::DEX)).second += consts::abils::racial;
        m_abilities.at(static_cast<int>(AbilitiesEnum::STR)).second -= consts::abils::racial;
        break;
    case RaceEnum::HUMAN:
    case RaceEnum::HALF_ELF: break;
    }
}
