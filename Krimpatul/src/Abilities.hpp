#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "krpch.hpp"

#include "Race.hpp"

class Abilities
{
public:
    Abilities(RaceEnum race);
    ~Abilities(){};

    auto        setOneAbility(const std::string, unsigned short) -> void;
    auto        setAbilities(const std::array<unsigned short, 6>) -> void;
    auto        getOneAbility(const std::string) const -> std::pair<std::string, unsigned short>;
    auto        getAbilities() const -> std::map<std::string, unsigned short>;
    auto        getAbilityMod(std::string) const -> short;
    auto        resetAbilities(RaceEnum) -> void;
    friend auto operator<<(std::ostream &out, const Abilities &abilities)
        -> std::ostream &;

private:
    auto setRacialAdjustment(const RaceEnum race) -> void;
    std::map<std::string, unsigned short> m_abilities{
        {"STR", 8}, {"DEX", 8}, {"CON", 8}, {"INT", 8}, {"WIS", 8}, {"CHA", 8}};
};

auto operator<<(std::ostream &out, const Abilities &abilities)
    -> std::ostream &;

#endif
