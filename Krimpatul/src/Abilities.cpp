#include "krpch.hpp"

#include "Abilities.hpp"
#include <cstddef>

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

auto Abilities::setOneAbility(const unsigned short position,
                              unsigned short       value) -> void
{
    m_abilities.at(position).second = value;
}

auto Abilities::setAbilities(const std::array<unsigned short, consts::abils::count> values) -> void
{
    for(size_t i = 0; i < values.size(); ++i) { m_abilities.at(i).second = values.at(i); }
}

auto Abilities::getOneAbility(const unsigned short position) const
    -> std::pair<std::string, unsigned short>
{
    return m_abilities.at(position);
}

auto Abilities::getAbilities() const
    -> std::array<std::pair<std::string, unsigned int>, consts::abils::count>
{
    return m_abilities;
}

// The formula to get an Ability modifier is: (Ability - 10) / 2
auto Abilities::getAbilityMod(unsigned short position) const -> short
{
    return std::ceil((m_abilities.at(position).second - consts::abils::form10) /
                     consts::abils::form2);
}

auto Abilities::resetAbilities(const RaceEnum race) -> void
{
    for(auto x : m_abilities) { x.second = consts::abils::base; }
    setRacialAdjustment(race);
}

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

// TODO: see if I can find a better solution to print individual abilities, as
// well as multiples and/or everything.
auto operator<<(std::ostream &out, const Abilities &abilities) -> std::ostream &
{
    for(auto x : abilities.m_abilities) { out << x.first << " " << x.second << '\n'; }
    return out;
}
