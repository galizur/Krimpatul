#ifndef CLASS_HPP_
#define CLASS_HPP_

#include <vector>
#include <string>
#include <string_view>
#include <ostream>

class Cclass
{
private:
    std::vector<std::string> m_class;

public:
    Cclass(std::vector<std::string_view> /*list*/);

    friend auto operator<<(std::ostream & /*out*/, const Cclass & /*cclass*/) -> std::ostream &;
};

#endif
