#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "krpch.hpp"

#include "Race.hpp"

class Abilities
{
    using ArrayOfPairs = std::array<std::pair<std::string, unsigned int>, consts::abils::count>;

public:
    // Abilities are modified by race.
    Abilities(RaceEnum race);
    ~Abilities()                 = default;
    Abilities(const Abilities &) = default;
    auto operator=(const Abilities &) -> Abilities & = default;
    Abilities(Abilities &&)                          = default;
    auto operator=(Abilities &&) -> Abilities & = default;

    auto setOneAbility(unsigned short /*position*/, unsigned short /*value*/) -> void;
    auto setAbilities(std::array<unsigned short, consts::abils::count> /*values*/) -> void;

    [[nodiscard]] auto getOneAbility(unsigned short /*position*/) const
        -> std::pair<std::string, unsigned short>;
    [[nodiscard]] auto getAbilities() const -> ArrayOfPairs;
    [[nodiscard]] auto getAbilityMod(unsigned short /*position*/) const -> short;

    auto resetAbilities(RaceEnum /*race*/) -> void;

    friend auto operator<<(std::ostream &out, const Abilities &abilities) -> std::ostream &;

private:
    auto setRacialAdjustment(RaceEnum race) -> void;

    ArrayOfPairs m_abilities;
};

auto operator<<(std::ostream &out, const Abilities &abilities)
    -> std::ostream &;

#endif
