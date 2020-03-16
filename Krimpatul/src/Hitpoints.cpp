#include "krpch.hpp"

#include "Hitpoints.hpp"

// We first set hitpoints to 0 since it will change immediately.
HitPoints::HitPoints(ClassEnum cclass, int constitution, int level) : m_hitpoints{0}
{
    setHitPointsFirstLevel(cclass, constitution);
    if(level > consts::level::base)
    {
        setHitPoints(cclass, constitution, level);
    }
}

// First level characters get full hitpoints, depending on their class and constitution score.
auto HitPoints::setHitPointsFirstLevel(const ClassEnum cclass, int constitution) -> void
{
    switch(cclass)
    {
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD: m_hitpoints = consts::hp::vlow + constitution; break;
    case ClassEnum::BARD:
    case ClassEnum::ROGUE: m_hitpoints = consts::hp::low + constitution; break;
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::RANGER: m_hitpoints = consts::hp::mid + constitution; break;
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN: m_hitpoints = consts::hp::high + constitution; break;
    case ClassEnum::BARBARIAN: m_hitpoints = consts::hp::vhigh + constitution; break;
    }
}

// Hitpoints after level one are set randomly. Each class has each own maximum hitpoints.
// Since hitpoints are calculated with the constitution modifier, it is possible to get negative
// hitpoints. In that case, the creature gets 1 hitpoint.
auto HitPoints::setHitPoints(const ClassEnum cclass, int constitution, int level) -> void
{
    std::default_random_engine generator;
    using int_dist = std::uniform_int_distribution<int>;
    for(std::size_t i = consts::level::base; i < level; ++i)
    {
        switch(cclass)
        {
        case ClassEnum::SORCERER:
        case ClassEnum::WIZARD:
        {
            int_dist distribution(consts::hp::min, consts::hp::vlow);
            int      hp = distribution(generator) + constitution;
            if(hp < consts::hp::min)
            {
                m_hitpoints += consts::hp::min;
            }
            else
            {
                m_hitpoints += hp;
            }
            break;
        }
        case ClassEnum::BARD:
        case ClassEnum::ROGUE:
        {
            int_dist distribution(consts::hp::min, consts::hp::low);
            int      hp = distribution(generator) + constitution;
            if(hp < consts::hp::min)
            {
                m_hitpoints += consts::hp::min;
            }
            else
            {
                m_hitpoints += hp;
            }
            break;
        }
        case ClassEnum::CLERIC:
        case ClassEnum::DRUID:
        case ClassEnum::MONK:
        case ClassEnum::RANGER:
        {
            int_dist distribution(consts::hp::min, consts::hp::mid);
            int      hp = distribution(generator) + constitution;
            if(hp < consts::hp::min)
            {
                m_hitpoints += consts::hp::min;
            }
            else
            {
                m_hitpoints += hp;
            }
            break;
        }
        case ClassEnum::FIGHTER:
        case ClassEnum::PALADIN:
        {
            int_dist distribution(consts::hp::min, consts::hp::high);
            int      hp = distribution(generator) + constitution;
            if(hp < consts::hp::min)
            {
                m_hitpoints += consts::hp::min;
            }
            else
            {
                m_hitpoints += hp;
            }
            break;
        }
        case ClassEnum::BARBARIAN:
        {
            int_dist distribution(consts::hp::min, consts::hp::vhigh);
            int      hp = distribution(generator) + constitution;
            if(hp < consts::hp::min)
            {
                m_hitpoints += consts::hp::min;
            }
            else
            {
                m_hitpoints += hp;
            }
            break;
        }
        }
    }
}

auto HitPoints::getHitPoints() const -> int
{
    return m_hitpoints;
}
