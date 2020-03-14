#include "krpch.hpp"

#include "Size.hpp"

Size::Size(SizeEnum size) : m_size{size}, m_size_mod{0}
{
    enumToStringMap.insert({{SizeEnum::FINE, "Fine"},
                            {SizeEnum::DIMINUTIVE, "Diminutive"},
                            {SizeEnum::TINY, "Tiny"},
                            {SizeEnum::SMALL, "Small"},
                            {SizeEnum::MEDIUM, "Medium"},
                            {SizeEnum::LARGE_TALL, "Large (Tall)"},
                            {SizeEnum::LARGE_LONG, "Large (Long)"},
                            {SizeEnum::HUGE_TALL, "Huge (Tall)"},
                            {SizeEnum::HUGE_LONG, "Huge (Long)"},
                            {SizeEnum::GARGANTUAN_TALL, "Gargantuan (Tall)"},
                            {SizeEnum::GARGANTUAN_LONG, "Gargantuan (Long)"},
                            {SizeEnum::COLOSSAL_TALL, "Colossal (Tall)"},
                            {SizeEnum::COLOSSAL_LONG, "Colossal (Long)"}});
}

auto Size::setSize(const SizeEnum size) -> void
{
    m_size = size;
}

auto Size::setSizeMod(const SizeEnum size) -> void
{
    switch(size)
    {
    case SizeEnum::FINE: m_size_mod = 8; break;
    case SizeEnum::DIMINUTIVE: m_size_mod = 4; break;
    case SizeEnum::TINY: m_size_mod = 2; break;
    case SizeEnum::SMALL: m_size_mod = 1; break;
    case SizeEnum::LARGE_TALL:
    case SizeEnum::LARGE_LONG: m_size_mod = -1; break;
    case SizeEnum::HUGE_TALL:
    case SizeEnum::HUGE_LONG: m_size_mod = -2; break;
    case SizeEnum::GARGANTUAN_TALL:
    case SizeEnum::GARGANTUAN_LONG: m_size_mod = -4; break;
    case SizeEnum::COLOSSAL_TALL:
    case SizeEnum::COLOSSAL_LONG: m_size_mod = -8; break;
    case SizeEnum::MEDIUM:
    default: m_size_mod = 0; break;
    }
}

auto Size::getSize() const -> SizeEnum
{
    return m_size;
}

auto Size::getSizeMod() const -> short
{
    return m_size_mod;
}

auto operator<<(std::ostream &out, const Size &size) -> std::ostream &
{
    out << size.enumToStringMap.find(size.m_size)->second;
    return out;
}
