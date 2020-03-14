#ifndef ALIGNMENT_HPP
#define ALIGNMENT_HPP

#include "krpch.hpp"

enum class AlignEnum
{
    LAWFUL_GOOD,
    NEUTRAL_GOOD,
    CHAOTIC_GOOD,
    LAWFUL_NEUTRAL,
    NEUTRAL,
    CHAOTIC_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_EVIL,
    CHAOTIC_EVIL
};

class Alignment
{
public:
    auto        setAlignment(AlignEnum /*align*/) -> void;
    [[nodiscard]] auto        getAlignment() const -> AlignEnum;
    friend auto operator<<(std::ostream &out, const Alignment &align)
        -> std::ostream &;

protected:
    Alignment(AlignEnum align = AlignEnum::LAWFUL_GOOD);
    virtual ~Alignment()= default;;

private:
    AlignEnum                        m_alignment;
    std::map<AlignEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const Alignment &align) -> std::ostream &;

#endif
