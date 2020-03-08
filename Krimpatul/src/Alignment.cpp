#include "krpch.hpp"

#include "Alignment.hpp"

Alignment::Alignment(AlignEnum align) : m_alignment{align}
{
    enumToStringMap.insert({{AlignEnum::LAWFUL_GOOD, "Lawful Good"},
                            {AlignEnum::NEUTRAL_GOOD, "Neutral Good"},
                            {AlignEnum::CHAOTIC_GOOD, "Chaotic Good"},
                            {AlignEnum::LAWFUL_NEUTRAL, "Lawful Neutral"},
                            {AlignEnum::NEUTRAL, "Neutral"},
                            {AlignEnum::LAWFUL_EVIL, "Lawful Evil"},
                            {AlignEnum::NEUTRAL_EVIL, "Neutral Evil"},
                            {AlignEnum::CHAOTIC_EVIL, "Chaotic Evil"}});
}

auto Alignment::setAlignment(const AlignEnum align) -> void
{
    m_alignment = align;
}

auto Alignment::getAlignment() const -> AlignEnum
{
    return m_alignment;
}

auto operator<<(std::ostream &out, const Alignment &align) -> std::ostream &
{
    out << align.enumToStringMap.find(align.m_alignment)->second;
    return out;
}
