#include "krpch.hpp"

#include "Abilities.hpp"

Abilities::Abilities(RaceEnum race)
    : m_abilities{{{"STR", constants::abilities::base},
                   {"DEX", constants::abilities::base},
                   {"CON", constants::abilities::base},
                   {"INT", constants::abilities::base},
                   {"WIS", constants::abilities::base},
                   {"CHA", constants::abilities::base}}}
{
    setRacialAdjustment(race);
}

auto Abilities::setOneAbility(const std::string ability, unsigned short value)
    -> void
{
    m_abilities.find(ability)->second = value;
}

auto Abilities::setAbilities(
    const std::array<unsigned short, constants::abilities::count> values)
    -> void
{
    // TODO: find a better implementation.
    m_abilities.find("STR")->second = values[0];
    m_abilities.find("DEX")->second = values[1];
    m_abilities.find("CON")->second = values[2];
    m_abilities.find("INT")->second = values[3];
    m_abilities.find("WIS")->second = values[4];
    m_abilities.find("CHA")->second = values[5];
}

auto Abilities::getOneAbility(const std::string value) const -> std::pair<std::string, unsigned short>
{
    return std::make_pair(m_abilities.find(value)->first, m_abilities.find(value)->second);
}

auto Abilities::getAbilities() const -> std::map<std::string, unsigned short>
{
    return m_abilities;
}

// The formula to get an Ability modifier is: (Ability - 10) / 2
auto Abilities::getAbilityMod(std::string ability) const -> short
{
    return std::ceil((m_abilities.find(ability)->second - 10) / 2);
}

auto Abilities::resetAbilities(const RaceEnum race) -> void
{
    for(auto x : m_abilities) x.second = constants::abilities::base;
    setRacialAdjustment(race);
}

auto Abilities::setRacialAdjustment(const RaceEnum race) -> void
{
    switch(race)
    {
    case RaceEnum::DWARF:
        m_abilities.find("CON")->second += constants::abilities::racial;
        m_abilities.find("CHA")->second -= constants::abilities::racial;
        break;
    case RaceEnum::ELF:
        m_abilities.find("DEX")->second += constants::abilities::racial;
        m_abilities.find("CON")->second -= constants::abilities::racial;
        break;
    case RaceEnum::GNOME:
        m_abilities.find("CON")->second += constants::abilities::racial;
        m_abilities.find("STR")->second -= constants::abilities::racial;
        break;
    case RaceEnum::HALF_ORC:
        m_abilities.find("STR")->second += constants::abilities::racial;
        m_abilities.find("INT")->second -= constants::abilities::racial;
        m_abilities.find("CHA")->second -= constants::abilities::racial;
        break;
    case RaceEnum::HALFLING:
        m_abilities.find("DEX")->second += constants::abilities::racial;
        m_abilities.find("STR")->second -= constants::abilities::racial;
        break;
    case RaceEnum::HUMAN:
    case RaceEnum::HALF_ELF: break;
    }
}

// TODO: see if I can find a better solution to print individual abilities, as
// well as multiples and/or everything.
auto operator<<(std::ostream &out, const Abilities &abilities) -> std::ostream &
{
    out << "STR: " << abilities.m_abilities.find("STR")->second << '\n'
        << "DEX: " << abilities.m_abilities.find("DEX")->second << '\n'
        << "CON: " << abilities.m_abilities.find("CON")->second << '\n'
        << "INT: " << abilities.m_abilities.find("INT")->second << '\n'
        << "WIS: " << abilities.m_abilities.find("WIS")->second << '\n'
        << "CHA: " << abilities.m_abilities.find("CHA")->second << '\n';
    return out;
}
