#ifndef CCLASS_HPP
#define CCLASS_HPP

#include "krpch.hpp"

enum class ClassEnum
{
    BARBARIAN,
    BARD,
    CLERIC,
    DRUID,
    FIGHTER,
    MONK,
    PALADIN,
    RANGER,
    ROGUE,
    SORCERER,
    WIZARD
};

class CClass
{
public:
    auto        setClass(ClassEnum /*cclass*/) -> void;
    [[nodiscard]] auto        getClass() const -> ClassEnum;
    friend auto operator<<(std::ostream &out, const CClass &cclass)
        -> std::ostream &;

protected:
    CClass(ClassEnum cclass = ClassEnum::BARBARIAN);
    virtual ~CClass() = default;

private:
    ClassEnum                        m_class;
    std::map<ClassEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const CClass &cclass) -> std::ostream &;

#endif
