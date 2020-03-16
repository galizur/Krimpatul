#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "krpch.hpp"

#include "Race.hpp"

class Abilities
{
    using ArrayOfPairs = std::array<std::pair<std::string, unsigned int>, consts::abils::count>;

public:
    /* Constructors */
    // Abilities are modified by race, so we need to know what race we are dealing with.
    Abilities(RaceEnum race);
    ~Abilities()                 = default;
    Abilities(const Abilities &) = default;
    auto operator=(const Abilities &) -> Abilities & = default;
    Abilities(Abilities &&)                          = default;
    auto operator=(Abilities &&) -> Abilities & = default;
    /******************/
    /* Setters */
    // Sometimes we need to change only one of the abilities.
    auto setOneAbility(unsigned short /*position*/, unsigned short /*value*/) -> void;
    // Other times we need to change them all.
    auto setAbilities(std::array<unsigned short, consts::abils::count> /*values*/) -> void;
    /******************/
    /* Getters */
    // [[nodiscard]] warns the programmer if the returned object is discarded by the caller.
    [[nodiscard]] auto getOneAbility(unsigned short /*position*/) const
        -> std::pair<std::string, unsigned short>;
    [[nodiscard]] auto getAbilities() const -> ArrayOfPairs;
    // An ability modifier is a special number in D&D.
    [[nodiscard]] auto getAbilityMod(unsigned short /*position*/) const -> short;
    /********************/
    // Set abilities back to their base number (8).
    auto resetAbilities(RaceEnum /*race*/) -> void;

private:
    // Sets the abilities acording to the race of the creature.
    auto setRacialAdjustment(RaceEnum race) -> void;

    ArrayOfPairs m_abilities;
};

#endif
