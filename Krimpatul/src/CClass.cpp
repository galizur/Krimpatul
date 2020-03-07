#include "krpch.hpp"

#include "CClass.hpp"

CClass::CClass(ClassEnum cclass) : m_class{cclass}
{
    enumToStringMap.insert({{ClassEnum::BARBARIAN, "Barbarian"},
                            {ClassEnum::BARD, "Bard"},
                            {ClassEnum::CLERIC, "Cleric"},
                            {ClassEnum::DRUID, "Druid"},
                            {ClassEnum::FIGHTER, "Fighter"},
                            {ClassEnum::MONK, "Monk"},
                            {ClassEnum::PALADIN, "Paladin"},
                            {ClassEnum::RANGER, "Ranger"},
                            {ClassEnum::ROGUE, "Rogue"},
                            {ClassEnum::SORCERER, "Sorcerer"},
                            {ClassEnum::WIZARD, "Wizard"}});
}

auto CClass::setClass(const ClassEnum cclass) -> void
{
    m_class = cclass;
}

auto CClass::getClass() const -> ClassEnum
{
    return m_class;
}

auto operator<<(std::ostream &out, const CClass &cclass) -> std::ostream &
{
    out << cclass.enumToStringMap.find(cclass.m_class)->second;
    return out;
}
