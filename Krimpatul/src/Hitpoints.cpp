#include "krpch.hpp"

#include "Hitpoints.hpp"

HitPoints::HitPoints(ClassEnum cclass, short ability) : m_hitpoints{0}
{
    setHitPointsFirstLevel(cclass, ability);
}

auto HitPoints::setHitPointsFirstLevel(const ClassEnum cclass, short ability)
    -> void
{
    switch(cclass)
    {
    case ClassEnum::SORCERER:
    case ClassEnum::WIZARD:
        m_hitpoints = constants::hitpoints::vlow + ability;
        break;
    case ClassEnum::BARD:
    case ClassEnum::ROGUE:
        m_hitpoints = constants::hitpoints::low + ability;
        break;
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::RANGER:
        m_hitpoints = constants::hitpoints::mid + ability;
        break;
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
        m_hitpoints = constants::hitpoints::high + ability;
        break;
    case ClassEnum::BARBARIAN:
        m_hitpoints = constants::hitpoints::vhigh + ability;
        break;
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
        std::uniform_int_distribution<unsigned int> distribution(
            1, constants::hitpoints::vlow);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::BARD:
    case ClassEnum::ROGUE:
    {
        std::uniform_int_distribution<unsigned int> distribution(
            1, constants::hitpoints::low);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::CLERIC:
    case ClassEnum::DRUID:
    case ClassEnum::MONK:
    case ClassEnum::RANGER:
    {
        std::uniform_int_distribution<unsigned int> distribution(
            1, constants::hitpoints::mid);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::FIGHTER:
    case ClassEnum::PALADIN:
    {
        std::uniform_int_distribution<unsigned int> distribution(
            1, constants::hitpoints::high);
        m_hitpoints += distribution(generator) + ability;
        break;
    }
    case ClassEnum::BARBARIAN:
    {
        std::uniform_int_distribution<unsigned int> distribution(
            1, constants::hitpoints::vhigh);
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
