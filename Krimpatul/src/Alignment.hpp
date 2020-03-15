#ifndef ALIGNMENT_HPP
#define ALIGNMENT_HPP

#include "krpch.hpp"

class Alignment
{
public:
    auto               setAlignment(AlignEnum /*align*/) -> void;
    [[nodiscard]] auto getAlignment() const -> AlignEnum;
    friend auto        operator<<(std::ostream &out, const Alignment &align) -> std::ostream &;

protected:
    Alignment(AlignEnum align = AlignEnum::LAWFUL_GOOD);
    virtual ~Alignment() = default;
    ;

private:
    AlignEnum                        m_alignment;
    std::map<AlignEnum, std::string> enumToStringMap;
};

auto operator<<(std::ostream &out, const Alignment &align) -> std::ostream &;

#endif
