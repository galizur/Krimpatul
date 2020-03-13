#ifndef SIZE_HPP
#define SIZE_HPP

#include "krpch.hpp"

enum class SizeEnum
{
    FINE,
    DIMINUTIVE,
    TINY,
    SMALL,
    MEDIUM,
    LARGE_TALL,
    LARGE_LONG,
    HUGE_TALL,
    HUGE_LONG,
    GARGANTUAN_TALL,
    GARGANTUAN_LONG,
    COLOSSAL_TALL,
    COLOSSAL_LONG
};

class Size
{
public:
    auto setSize(const SizeEnum) -> void;
    auto setSizeMod(const SizeEnum) -> void;

    auto getSize() const -> SizeEnum;
    auto getSizeMod() const -> short;

    friend auto operator<<(std::ostream &out, const Size &size)
        -> std::ostream &;

protected:
    Size(SizeEnum size = SizeEnum::MEDIUM);
    virtual ~Size(){};

private:
    SizeEnum                        m_size;
    short                           m_size_mod;
    std::map<SizeEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &os, const Size &size) -> std::ostream &;

#endif
