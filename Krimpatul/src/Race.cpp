#include "krpch.hpp"

#include "Race.hpp"

Race::Race(RaceEnum race, SizeEnum size) : m_race{race}
{
    enumToStringMap.insert({{RaceEnum::DWARF, "Dwarf"},
                            {RaceEnum::ELF, "Elf"},
                            {RaceEnum::GNOME, "Gnome"},
                            {RaceEnum::HALFLING, "Halfling"},
                            {RaceEnum::HALF_ELF, "Half-elf"},
                            {RaceEnum::HALF_ORC, "Half-orc"},
                            {RaceEnum::HUMAN, "Human"}});
}

auto Race::setRace(const RaceEnum race) -> void
{
    m_race = race;
}

auto Race::getRace() const -> RaceEnum
{
    return m_race;
}

auto operator<<(std::ostream &out, const Race &race) -> std::ostream &
{
    out << race.enumToStringMap.find(race.m_race)->second;
    return out;
}
