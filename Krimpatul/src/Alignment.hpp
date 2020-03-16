#ifndef ALIGNMENT_HPP
#define ALIGNMENT_HPP

#include "krpch.hpp"

class Alignment
{
public:
    /* Deleted constructors */
    Alignment(const Alignment &) = delete;
    auto operator=(const Alignment &) -> Alignment & = delete;
    Alignment(Alignment &&)                          = delete;
    auto operator=(Alignment &&) -> Alignment & = delete;
    /*********************/
    /* Setters */
    auto setAlignment(AlignEnum /*alignment*/) -> void;
    /*********************/
    /* Getters */
    [[nodiscard]] auto getAlignment() const -> AlignEnum;
    /*********************/
protected:
    /* Constructors */
    Alignment(AlignEnum /*alignment*/);
    virtual ~Alignment() = default;
    /*********************/
private:
    AlignEnum m_alignment;
};

#endif
