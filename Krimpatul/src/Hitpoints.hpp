#ifndef HITPOINTS_HPP
#define HITPOINTS_HPP

#include "CClass.hpp"

class HitPoints
{
public:
    HitPoints(ClassEnum cclass, short ability);
    ~HitPoints(){};

    auto setHitPoints(const ClassEnum cclass, short ability) -> void;
    auto setHitPointsFirstLevel(const ClassEnum cclass, short ability) -> void;
    auto getHitPoints() const -> unsigned int;
    friend auto operator<<(std::ostream &out, const HitPoints &hp)
        -> std::ostream &;

private:
    unsigned int m_hitpoints;
};

auto operator<<(std::ostream &out, const HitPoints &hp) -> std::ostream &;

#endif
