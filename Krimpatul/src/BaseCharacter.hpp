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
    auto setAttackBonusMelee(const BaseAbilities, const Abilities, const Race)
        -> void;
    auto setAttackBonusRanged(const BaseAbilities, const Abilities, const Race,
                              const short) -> void;

    auto getAttackBonusMelee() const -> int;
    auto getAttackBonusRanged() const -> int;

protected:
    BaseCharacter(RaceEnum  race   = RaceEnum::DWARF,
                  ClassEnum cclass = ClassEnum::BARBARIAN,
                  AlignEnum align  = AlignEnum::LAWFUL_GOOD);
    virtual ~BaseCharacter(){};

private:
    unsigned short m_level;
    Abilities      m_abilities;
    BaseAbilities  m_base_abilities;
    HitPoints      m_hitpoints;
    int            m_attack_bonus_melee{0};
    int            m_attack_bonus_ranged{0};
};

#endif
