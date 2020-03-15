#ifndef RACE_HPP
#define RACE_HPP

#include "krpch.hpp"

#include "Size.hpp"

class Race : public Size
{
public:
    Race(const Size &) = delete;
    auto operator=(const Race &) -> Race & = delete;
    Race(Race &&)                          = delete;
    auto operator=(Race &&) -> Race & = delete;

    auto               setRace(RaceEnum /*race*/) -> void;
    [[nodiscard]] auto getRace() const -> RaceEnum;
    friend auto        operator<<(std::ostream &out, const Race &race) -> std::ostream &;

protected:
    Race(RaceEnum race = RaceEnum::HUMAN, SizeEnum size = SizeEnum::MEDIUM);
    ~Race() override = default;

private:
    RaceEnum                        m_race;
    std::map<RaceEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const Race &race) -> std::ostream &;

#endif
