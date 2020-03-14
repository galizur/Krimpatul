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
    //! Copy constructor
    Size(const Size &other) = delete;
    //! Move constructor
    Size(Size &&other) = delete;
    //! Copy assignment operator
    auto operator=(const Size &other) -> Size & = delete;
    //! Move assignment operator
    auto operator=(Size &&other) -> Size & = delete;

    auto setSize(SizeEnum) -> void;
    auto setSizeMod(SizeEnum) -> void;

    [[nodiscard]] auto getSize() const -> SizeEnum;
    [[nodiscard]] auto getSizeMod() const -> short;

    friend auto operator<<(std::ostream &out, const Size &size)
        -> std::ostream &;

protected:
    Size(SizeEnum size = SizeEnum::MEDIUM);
    virtual ~Size() = default;

private:
    SizeEnum                        m_size;
    short                           m_size_mod;
    std::map<SizeEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const Size &size) -> std::ostream &;

#endif
