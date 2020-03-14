#ifndef BASEABILITIES_HPP
#define BASEABILITIES_HPP

#include "krpch.hpp"

#include "CClass.hpp"

class BaseAbilities
{
public:
    BaseAbilities(ClassEnum, unsigned short);
    ~BaseAbilities() = default;

    auto setBaseAttackBonus(ClassEnum, unsigned short) -> void;
    auto setBaseSaveBonus(ClassEnum, unsigned short) -> void;

    [[nodiscard]] auto getBaseAttackBonus() const -> unsigned short;
    [[nodiscard]] auto getBaseSaveBonus() const
        -> std::map<std::string, unsigned short>;
    [[nodiscard]] auto getOneSave(std::string) const
        -> std::pair<std::string, unsigned short>;

private:
    auto calculateBaseSaveHigh(unsigned short) -> unsigned short;
    auto calculateBaseSaveLow(unsigned short) -> unsigned short;

    unsigned short                        m_base_attack;
    std::map<std::string, unsigned short> m_base_save;
};

#endif
