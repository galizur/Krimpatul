#include "krpch.hpp"

#include "Race.hpp"

Race::Race(RaceEnum race) : m_race{race}, Size(race) {}

auto Race::setRace(const RaceEnum race) -> void
{
    m_race = race;
}

auto Race::getRace() const -> RaceEnum
{
    return m_race;
}
