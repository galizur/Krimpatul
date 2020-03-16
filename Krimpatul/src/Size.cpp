#include "krpch.hpp"

#include "Size.hpp"

// We first set the size according to the Players Handbook. Then we calculate the modifier according
// to the size.
Size::Size(RaceEnum race) : m_size_mod{0}
{
    switch(race)
    {
    case RaceEnum::DWARF:
    case RaceEnum::HALFLING:
    case RaceEnum::GNOME:
        m_size = SizeEnum::SMALL;
        setSizeMod(SizeEnum::SMALL);
        break;
    case RaceEnum::HALF_ELF:
    case RaceEnum::HALF_ORC:
    case RaceEnum::ELF:
    case RaceEnum::HUMAN:
    default:
        m_size = SizeEnum::MEDIUM;
        setSizeMod(SizeEnum::MEDIUM);
        break;
    }
}

auto Size::setSize(const SizeEnum size) -> void
{
    m_size = size;
}

// Smaller sizes get more of a modifier, while bigger ones get less. There is no difference between
// a long and tall creature, they get the same modifier. Modifiers are always *2 of the previous
// size.
auto Size::setSizeMod(const SizeEnum size) -> void
{
    switch(size)
    {
    case SizeEnum::FINE: m_size_mod = consts::size::mod8; break;
    case SizeEnum::DIMINUTIVE: m_size_mod = consts::size::mod4; break;
    case SizeEnum::TINY: m_size_mod = consts::size::mod2; break;
    case SizeEnum::SMALL: m_size_mod = consts::size::mod1; break;
    case SizeEnum::LARGE_TALL:
    case SizeEnum::LARGE_LONG: m_size_mod = -consts::size::mod1; break;
    case SizeEnum::HUGE_TALL:
    case SizeEnum::HUGE_LONG: m_size_mod = -consts::size::mod2; break;
    case SizeEnum::GARGANTUAN_TALL:
    case SizeEnum::GARGANTUAN_LONG: m_size_mod = -consts::size::mod4; break;
    case SizeEnum::COLOSSAL_TALL:
    case SizeEnum::COLOSSAL_LONG: m_size_mod = -consts::size::mod8; break;
    case SizeEnum::MEDIUM:
    default: m_size_mod = consts::size::mod0; break;
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
