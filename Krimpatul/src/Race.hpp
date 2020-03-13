#ifndef RACE_HPP
#define RACE_HPP

#include "krpch.hpp"

#include "Size.hpp"

enum class RaceEnum
{
    DWARF,
    ELF,
    GNOME,
    HALFLING,
    HALF_ELF,
    HALF_ORC,
    HUMAN
};

class Race : public Size
{
public:
    auto        setRace(const RaceEnum) -> void;
    auto        getRace() const -> RaceEnum;
    friend auto operator<<(std::ostream &out, const Race &race)
        -> std::ostream &;

protected:
    Race(RaceEnum race = RaceEnum::HUMAN, SizeEnum size = SizeEnum::MEDIUM);
    virtual ~Race(){};

private:
    RaceEnum                        m_race;
    std::map<RaceEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const Race &race) -> std::ostream &;

#endif
