#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "krpch.hpp"

#include "Race.hpp"

class Abilities
{
public:
    // Abilities are modified by race.
    Abilities(RaceEnum race);
    ~Abilities() = default;

    auto setOneAbility(std::string /*ability*/, unsigned short /*value*/)
        -> void;
    auto setAbilities(
        std::array<unsigned short, constants::abilities::count> /*values*/)
        -> void;

    [[nodiscard]] auto getOneAbility(std::string /*value*/) const
        -> std::pair<std::string, unsigned short>;
    [[nodiscard]] auto getAbilities() const
        -> std::map<std::string, unsigned short>;
    [[nodiscard]] auto getAbilityMod(std::string /*ability*/) const -> short;

    auto resetAbilities(RaceEnum /*race*/) -> void;

    friend auto operator<<(std::ostream &out, const Abilities &abilities)
        -> std::ostream &;

private:
    auto setRacialAdjustment(RaceEnum race) -> void;
    std::map<std::string, unsigned short> m_abilities;
};

auto operator<<(std::ostream &out, const Abilities &abilities)
    -> std::ostream &;

#endif
