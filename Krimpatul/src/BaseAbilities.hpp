#ifndef BASEABILITIES_HPP
#define BASEABILITIES_HPP

#include "CClass.hpp"

class BaseAbilities
{
public:
    BaseAbilities(ClassEnum, unsigned short);
    ~BaseAbilities(){};

    auto setBaseAttackBonus(const ClassEnum, const unsigned short) -> void;
    auto setBaseSaveBonus(const ClassEnum, const unsigned short) -> void;

    auto getBaseAttackBonus() const -> unsigned short;
    auto getBaseSaveBonus() const -> std::map<std::string, unsigned short>;
    auto getOneSave(const std::string) const
        -> std::pair<std::string, unsigned short>;

private:
    auto calculateBaseSaveHigh(const unsigned short) -> unsigned short;
    auto calculateBaseSaveLow(const unsigned short) -> unsigned short;

    unsigned short m_base_attack;
    std::map<std::string, unsigned short> m_base_save{
        {"FORT", 0}, {"REF", 0}, {"WILL", 0}};
};

#endif
