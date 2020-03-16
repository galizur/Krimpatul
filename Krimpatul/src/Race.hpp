#ifndef RACE_HPP
#define RACE_HPP

#include "krpch.hpp"

#include "Size.hpp"

class Race : public Size
{
public:
    /* Deleted constructors */
    Race(const Race &) = delete;
    auto operator=(const Race &) -> Race & = delete;
    Race(Race &&)                          = delete;
    auto operator=(Race &&) -> Race & = delete;
    /*************************/
    /* Setters */
    auto setRace(RaceEnum /*race*/) -> void;
    /*************************/
    /* Getters */
    [[nodiscard]] auto getRace() const -> RaceEnum;
    /*************************/
protected:
    /* Constructors */
    Race(RaceEnum /*race*/);
    ~Race() override = default;
    /**************************/
private:
    RaceEnum m_race;
};

#endif
