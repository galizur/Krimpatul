#ifndef BASEABILITIES_HPP
#define BASEABILITIES_HPP

#include "krpch.hpp"

#include "CClass.hpp"

class BaseAbilities
{
public:
    using ArrayOfPairs = std::array<std::pair<std::string, unsigned short>, consts::saves::count>;
    /* Constructors */
    // Base abilities are dependant on the class of the creature, as well as the level of the class.
    // We can safely assume that sometimes we start from the first level.
    BaseAbilities(ClassEnum /*cclass*/, unsigned short class_level = 1);
    ~BaseAbilities()                     = default;
    BaseAbilities(const BaseAbilities &) = default;
    auto operator=(const BaseAbilities &) -> BaseAbilities & = default;
    BaseAbilities(BaseAbilities &&)                          = default;
    auto operator=(BaseAbilities &&) -> BaseAbilities & = default;
    /********************/
    /* Setters */
    auto setBaseAttackBonus(ClassEnum /*cclass*/, unsigned short /*level*/) -> void;
    auto setBaseSaveBonus(ClassEnum /*cclass*/, unsigned short /*level*/) -> void;
    /*******************/
    /* Getters */
    [[nodiscard]] auto getBaseAttackBonus() const -> unsigned short;
    [[nodiscard]] auto getBaseSaveBonus() const -> ArrayOfPairs;
    [[nodiscard]] auto getOneSave(unsigned short /*position*/) const
        -> std::pair<std::string, unsigned short>;
    /*******************/
private:
    // Base save bonuses come in high and low flavors.
    static auto calculateBaseSaveHigh(unsigned short /*level*/) -> unsigned short;
    static auto calculateBaseSaveLow(unsigned short /*level*/) -> unsigned short;

    unsigned short m_base_attack;
    ArrayOfPairs   m_base_save;
};

#endif
