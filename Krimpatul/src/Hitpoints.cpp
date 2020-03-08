#include "krpch.hpp"

#include "Hitpoints.hpp"

HitPoints::HitPoints(ClassEnum cclass, short ability)
{
    setHitPointsFirstLevel(cclass, ability);
}

auto HitPoints::setHitPointsFirstLevel(const ClassEnum cclass, short ability)
    -> void
{
    switch(cclass)
    {
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD: m_hitpoints = 4 + ability; break;
    case ClassEnum::BARD:
    case ClassEnum::ROGUE: m_hitpoints = 6 + ability; break;
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::RANGER: m_hitpoints = 8 + ability; break;
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN: m_hitpoints = 10 + ability; break;
    case ClassEnum::BARBARIAN: m_hitpoints = 12 + ability; break;
    }
}

auto HitPoints::setHitPoints(const ClassEnum cclass, short ability) -> void
{
    std::default_random_engine generator;
    switch(cclass)
    {
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
    {
        std::uniform_int_distribution<unsigned int> distribution(1, 4);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::BARD:
    case ClassEnum::ROGUE:
    {
        std::uniform_int_distribution<unsigned int> distribution(1, 6);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::RANGER:
    {
        std::uniform_int_distribution<unsigned int> distribution(1, 8);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
    {
        std::uniform_int_distribution<unsigned int> distribution(1, 10);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::BARBARIAN:
    {
        std::uniform_int_distribution<unsigned int> distribution(1, 12);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    }
}

auto HitPoints::getHitPoints() const -> unsigned int
{
    return m_hitpoints;
}

auto operator<<(std::ostream &out, const HitPoints &hp) -> std::ostream &
{
    out << hp.m_hitpoints;
    return out;
}
