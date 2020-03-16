#include "krpch.hpp"

#include "Alignment.hpp"

Alignment::Alignment(AlignEnum alignment) : m_alignment{alignment} {}

auto Alignment::setAlignment(const AlignEnum alignment) -> void
{
    m_alignment = alignment;
}

auto Alignment::getAlignment() const -> AlignEnum
{
    return m_alignment;
}
