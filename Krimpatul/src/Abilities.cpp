#include "krpch.hpp"

#include "Abilities.hpp"

Abilities::Abilities(RaceEnum race)
{
    setRacialAdjustment(race);
}

auto Abilities::setOneAbility(const std::string ability, unsigned short value)
    -> void
{
    m_abilities.find(ability)->second = value;
}

auto Abilities::setAbilities(const std::array<unsigned short, 6> values) -> void
{
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

auto Abilities::getAbilityMod(std::string ability) const -> short
{
    return std::ceil(m_abilities.find(ability)->second - 10 / 2);
}

auto Abilities::resetAbilities(const RaceEnum race) -> void
{
    std::map<std::string, unsigned short>::iterator it = m_abilities.begin();
    for(auto x : m_abilities) x.second = 8;
    setRacialAdjustment(race);
}

auto Abilities::setRacialAdjustment(const RaceEnum race) -> void
{
    switch(race)
    {
    case RaceEnum::DWARF:
        m_abilities.find("CON")->second += 2;
        m_abilities.find("CHA")->second -= 2;
        break;
    case RaceEnum::ELF:
        m_abilities.find("DEX")->second += 2;
        m_abilities.find("CON")->second -= 2;
        break;
    case RaceEnum::GNOME:
        m_abilities.find("CON")->second += 2;
        m_abilities.find("STR")->second -= 2;
        break;
    case RaceEnum::HALF_ORC:
        m_abilities.find("STR")->second += 2;
        m_abilities.find("INT")->second -= 2;
        m_abilities.find("CHA")->second -= 2;
        break;
    case RaceEnum::HALFLING:
        m_abilities.find("DEX")->second += 2;
        m_abilities.find("STR")->second -= 2;
        break;
    case RaceEnum::HUMAN:
    case RaceEnum::HALF_ELF: break;
    }
}

auto operator<<(std::ostream &out, const Abilities &abilities) -> std::ostream &
{
    out << "STR: " << abilities.m_abilities.find("STR")->second << " "
        << "DEX: " << abilities.m_abilities.find("DEX")->second << " "
        << "CON: " << abilities.m_abilities.find("CON")->second << " "
        << "INT: " << abilities.m_abilities.find("INT")->second << " "
        << "WIS: " << abilities.m_abilities.find("WIS")->second << " "
        << "CHA: " << abilities.m_abilities.find("CHA")->second;
    return out;
}
