#include "Race.hpp"

Race::Race(std::vector<std::string_view> list)
{
    m_race.insert(m_race.end(), list.begin(), list.end());
}

auto Race::getRace() const -> std::vector<std::string>
{
    return m_race;
}

auto operator<<(std::ostream &out, const Race &race) -> std::ostream &
{
    for(auto it = race.m_race.begin(); it != race.m_race.end(); ++it)
    {
        if(it != race.m_race.begin())
        {
            out << " ";
        }
        out << *it;
    }
    return out;
}
