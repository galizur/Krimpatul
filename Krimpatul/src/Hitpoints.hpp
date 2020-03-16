#ifndef HITPOINTS_HPP
#define HITPOINTS_HPP

#include "CClass.hpp"

class HitPoints
{
public:
    /* Constructors */
    // Hit points are dealt according to class, constitution and level.
    HitPoints(ClassEnum /*cclass*/, short /*constitution*/, unsigned int level = 1);
    ~HitPoints()                 = default;
    HitPoints(const HitPoints &) = default;
    auto operator=(const HitPoints &) -> HitPoints & = default;
    HitPoints(HitPoints &&)                          = default;
    auto operator=(HitPoints &&) -> HitPoints & = default;
    /******************/
    /* Setters */
    // Hitpoints are treated differently if they are for the first level.
    auto setHitPoints(ClassEnum /*cclass*/, short /*constitution*/, unsigned int /*level*/) -> void;
    auto setHitPointsFirstLevel(ClassEnum /*cclass*/, short /*constitution*/) -> void;
    /******************/
    /* Getters */
    [[nodiscard]] auto getHitPoints() const -> int;
    /******************/

private:
    int m_hitpoints;
};

#endif
