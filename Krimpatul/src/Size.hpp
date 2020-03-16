#ifndef SIZE_HPP
#define SIZE_HPP

#include "krpch.hpp"

class Size
{
public:
    /* Deleted Constructors */
    Size(const Size &other) = delete;
    Size(Size &&other)      = delete;
    auto operator=(const Size &other) -> Size & = delete;
    auto operator=(Size &&other) -> Size & = delete;
    /************************/
    /* Setters */
    auto setSize(SizeEnum /*size*/) -> void;
    auto setSizeMod(SizeEnum /*size*/) -> void;
    /************************/
    /* Getters */
    [[nodiscard]] auto getSize() const -> SizeEnum;
    [[nodiscard]] auto getSizeMod() const -> int;
    /************************/
protected:
    /* Constructors */
    Size(RaceEnum /*race*/);
    virtual ~Size() = default;
    /************************/
private:
    SizeEnum m_size;
    int      m_size_mod;
};

#endif
