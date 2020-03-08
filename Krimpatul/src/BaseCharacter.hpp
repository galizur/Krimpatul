#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "krpch.hpp"

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
    auto getAbilityMod(const unsigned short) -> short;

    unsigned short                        m_level{1};
    HitPoints                             m_hitpoints;
    std::map<std::string, unsigned short> m_abilities{
        {"STR", 8}, {"DEX", 8}, {"CON", 8}, {"INT", 8}, {"WIS", 8}, {"CHA", 8}};
};

#endif
