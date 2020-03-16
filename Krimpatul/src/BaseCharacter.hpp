#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "Constants.hpp"
#include "krpch.hpp"

#include "Abilities.hpp"
#include "Alignment.hpp"
#include "BaseAbilities.hpp"
#include "Race.hpp"
#include "CClass.hpp"
#include "Hitpoints.hpp"
#include <array>
#include <c++/9.2.1/x86_64-pc-linux-gnu/bits/c++config.h>
#include <string>
#include <utility>

class BaseCharacter : public Race, public CClass, public Alignment
{
    using ArrayOfPairs = std::array<std::pair<std::string, int>, consts::saves::count>;

public:
    /* Deleted Constructors */
    BaseCharacter(const BaseCharacter &) = delete;
    auto operator=(const BaseCharacter &) -> BaseCharacter & = delete;
    BaseCharacter(BaseCharacter &&)                          = delete;
    auto operator=(BaseCharacter &&) -> BaseCharacter & = delete;
    /************************/
    /* Setters */
    auto setAttackBonusMelee(BaseAbilities /*bab*/, Abilities /*str*/, Race /*size*/,
                             short /*misc*/) -> void;
    auto setAttackBonusRanged(BaseAbilities /*bab*/, Abilities /*dex*/, Race /*size*/,
                              short /*penalty*/, short /*misc*/) -> void;
    auto setSaves(std::array<int, consts::saves::count> /*values*/) -> void;
    auto setOneSave(unsigned short /*position*/, int /*value*/) -> void;
    auto setSpellResistance(unsigned short /*sr*/) -> void;
    auto setInitiative(short /*dex_mod*/, short /*misc*/) -> void;
    auto setGrapple(short /*bab*/, short /*str_mod*/, short /*size_mod*/, short /*misc*/) -> void;
    /************************/
    /* Getters */
    [[nodiscard]] auto getAttackBonusMelee() const -> int;
    [[nodiscard]] auto getAttackBonusRanged() const -> int;
    [[nodiscard]] auto getSaves() const -> ArrayOfPairs;
    [[nodiscard]] auto getOneSave(unsigned short /*position*/) const -> int;
    [[nodiscard]] auto getSpellResistance() const -> unsigned short;
    [[nodiscard]] auto getInitiative() const -> short;
    [[nodiscard]] auto getGrapple() const -> int;
    /************************/
protected:
    BaseCharacter(RaceEnum /*race*/, ClassEnum /*cclass*/, AlignEnum /*align*/);
    ~BaseCharacter() override = default;

private:
    Abilities      m_abilities;
    BaseAbilities  m_base_abilities;
    HitPoints      m_hitpoints;
    ArrayOfPairs   m_saves;
    unsigned short m_level{1};
    int            m_attack_bonus_melee{0};
    int            m_attack_bonus_ranged{0};
    unsigned short m_spell_resistance{0};
    short          m_initiative{0};
    int            m_grapple{0};
};

#endif
