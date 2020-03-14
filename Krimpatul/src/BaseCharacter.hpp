#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "krpch.hpp"

#include "Abilities.hpp"
#include "Alignment.hpp"
#include "BaseAbilities.hpp"
#include "Race.hpp"
#include "CClass.hpp"
#include "Hitpoints.hpp"

class BaseCharacter : public Race, public CClass, public Alignment
{
public:
    auto setAttackBonusMelee(BaseAbilities /*bab*/, Abilities /*str*/, Race /*size*/)
        -> void;
    auto setAttackBonusRanged(BaseAbilities /*bab*/, Abilities /*dex*/, Race /*size*/,
                              short /*penalty*/) -> void;

    [[nodiscard]] auto getAttackBonusMelee() const -> int;
    [[nodiscard]] auto getAttackBonusRanged() const -> int;

protected:
    BaseCharacter(RaceEnum  race   = RaceEnum::DWARF,
                  ClassEnum cclass = ClassEnum::BARBARIAN,
                  AlignEnum align  = AlignEnum::LAWFUL_GOOD);
    ~BaseCharacter() override= default;;

private:
    unsigned short m_level;
    Abilities      m_abilities;
    BaseAbilities  m_base_abilities;
    HitPoints      m_hitpoints;
    int            m_attack_bonus_melee{0};
    int            m_attack_bonus_ranged{0};
};

#endif
