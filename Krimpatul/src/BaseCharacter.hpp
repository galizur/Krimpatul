#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "Enumerators.hpp"
#include "krpch.hpp"

#include "Abilities.hpp"
#include "Alignment.hpp"
#include "BaseAbilities.hpp"
#include "Race.hpp"
#include "CClass.hpp"
#include "Hitpoints.hpp"

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
    auto setAttackBonusMelee(BaseAbilities /*bab*/, Abilities /*str*/, Race /*size*/, int /*misc*/)
        -> void;
    auto setAttackBonusRanged(BaseAbilities /*bab*/, Abilities /*dex*/, Race /*size*/,
                              int /*penalty*/, int /*misc*/) -> void;
    auto setSaves(std::array<int, consts::saves::count> /*values*/) -> void;
    auto setOneSave(int /*position*/, int /*value*/) -> void;
    auto setSpellResistance(int /*sr*/) -> void;
    auto setInitiative(int /*dex_mod*/, int /*misc*/) -> void;
    auto setGrapple(int /*bab*/, int /*str_mod*/, int /*size_mod*/, int /*misc*/) -> void;
    auto setArmorClass(int /*armor*/, int /*shield*/, int /*dex_mod*/, int /*size_mod*/,
                       int /*nat_armor*/, int /*defl_mod*/, int /*misc*/) -> void;
    auto setArmorTouch(int /*dex_mod*/, int /*size_mod*/, int /*defl_mod*/, int /*misc*/) -> void;
    auto setArmorFlat(int /*armor*/, int /*shield*/, int /*size_mod*/, int /*nat_armor*/,
                      int /*defl_mod*/, int /*misc*/) -> void;
    auto setSpeed(RaceEnum /*race*/, std::string /*armor_rating*/) -> void;
    /************************/
    /* Getters */
    [[nodiscard]] auto getAttackBonusMelee() const -> int;
    [[nodiscard]] auto getAttackBonusRanged() const -> int;
    [[nodiscard]] auto getSaves() const -> ArrayOfPairs;
    [[nodiscard]] auto getOneSave(int /*position*/) const -> int;
    [[nodiscard]] auto getSpellResistance() const -> int;
    [[nodiscard]] auto getInitiative() const -> int;
    [[nodiscard]] auto getGrapple() const -> int;
    [[nodiscard]] auto getArmorClass() const -> int;
    [[nodiscard]] auto getArmorTouch() const -> int;
    [[nodiscard]] auto getArmorFlat() const -> int;
    [[nodiscard]] auto getSpeed() const -> int;
    /************************/
protected:
    BaseCharacter(RaceEnum /*race*/, ClassEnum /*cclass*/, AlignEnum /*align*/);
    ~BaseCharacter() override = default;

private:
    Abilities     m_abilities;
    BaseAbilities m_base_abilities;
    HitPoints     m_hitpoints;
    ArrayOfPairs  m_saves;
    int           m_level{1};
    int           m_attack_bonus_melee{0};
    int           m_attack_bonus_ranged{0};
    int           m_spell_resistance{0};
    int           m_initiative{0};
    int           m_grapple{0};
    int           m_armor_class{consts::armor::base};
    int           m_armor_touch{consts::armor::base};
    int           m_armor_flat{consts::armor::base};
    int           m_speed{30};
};

#endif
