#ifndef BASECHARACTER_HPP
#define BASECHARACTER_HPP

#include "krpch.hpp"

#include "Race.hpp"
#include "CClass.hpp"

class BaseCharacter : public Race, public CClass
{
public:
protected:
    BaseCharacter(RaceEnum race = RaceEnum::DWARF, ClassEnum cclass = ClassEnum::BARBARIAN);
    virtual ~BaseCharacter(){};
private:

};

#endif
