#ifndef CCLASS_HPP
#define CCLASS_HPP

#include "krpch.hpp"

class CClass
{
public:
    /* Deleted constructors */
    CClass(const CClass &) = delete;
    auto operator=(const CClass &) -> CClass & = delete;
    CClass(CClass &&)                          = delete;
    auto operator=(CClass &&) -> CClass & = delete;
    /************************/
    /* Setters */
    auto setClass(ClassEnum /*cclass*/) -> void;
    /************************/
    /* Getters */
    [[nodiscard]] auto getClass() const -> ClassEnum;
    /************************/

protected:
    /* Constructors */
    CClass(ClassEnum cclass);
    virtual ~CClass() = default;
    /************************/

private:
    ClassEnum m_class;
};

#endif
