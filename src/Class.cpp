#include "Class.hpp"
#include <string_view>

Cclass::Cclass(std::vector<std::string_view> list)
{
    m_class.insert(m_class.end(), list.begin(), list.end());
}

auto operator<<(std::ostream &out, const Cclass &cclass) -> std::ostream &
{
    for(auto it = cclass.m_class.begin(); it != cclass.m_class.end(); ++it)
    {
        if(it != cclass.m_class.begin())
        {
            out << " ";
        }
        out << *it;
    }
    return out;
}
