#include "krpch.hpp"

#include "CClass.hpp"

CClass::CClass(ClassEnum cclass) : m_class{cclass} {}

auto CClass::setClass(const ClassEnum cclass) -> void
{
    m_class = cclass;
}

auto CClass::getClass() const -> ClassEnum
{
    return m_class;
}
