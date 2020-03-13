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

    auto setOneAbility(const std::string, unsigned short) -> void;
    auto setAbilities(
        const std::array<unsigned short, constants::abilities::count>) -> void;

    auto getOneAbility(const std::string) const
        -> std::pair<std::string, unsigned short>;
    auto getAbilities() const -> std::map<std::string, unsigned short>;
    auto getAbilityMod(std::string) const -> short;

    auto resetAbilities(RaceEnum) -> void;

    friend auto operator<<(std::ostream &out, const Abilities &abilities)
        -> std::ostream &;

private:
    auto setRacialAdjustment(const RaceEnum race) -> void;
    std::map<std::string, unsigned short> m_abilities;
};

auto operator<<(std::ostream &out, const Abilities &abilities)
    -> std::ostream &;

#endif
