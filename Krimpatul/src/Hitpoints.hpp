#ifndef HITPOINTS_HPP
#define HITPOINTS_HPP

#include "CClass.hpp"

class HitPoints
{
public:
    HitPoints(ClassEnum cclass, short ability);
    ~HitPoints()= default;;

    auto setHitPoints(ClassEnum cclass, short ability) -> void;
    auto setHitPointsFirstLevel(ClassEnum cclass, short ability) -> void;
    [[nodiscard]] auto getHitPoints() const -> unsigned int;
    friend auto operator<<(std::ostream &out, const HitPoints &hp)
        -> std::ostream &;

private:
    unsigned int m_hitpoints;
};

auto operator<<(std::ostream &out, const HitPoints &hp) -> std::ostream &;

#endif
