#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "krpch.hpp"

#include "Abilities.hpp"
#include "Alignment.hpp"
#include "Race.hpp"
#include "CClass.hpp"
#include "Hitpoints.hpp"

class BaseCharacter : public Race, public CClass, public Alignment
{
public:
protected:
    BaseCharacter(RaceEnum  race   = RaceEnum::DWARF,
                  ClassEnum cclass = ClassEnum::BARBARIAN,
                  AlignEnum align  = AlignEnum::LAWFUL_GOOD);
    virtual ~BaseCharacter(){};

private:
    Abilities      m_abilities;
    unsigned short m_level{1};
    HitPoints      m_hitpoints;
};

#endif
