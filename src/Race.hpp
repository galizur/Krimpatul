#ifndef RACE_HPP
#define RACE_HPP

#include <vector>
#include <string>
#include <string_view>
#include <ostream>

class Race
{
private:
    std::vector<std::string> m_race;

public:
    Race(std::vector<std::string_view> /*list*/);

    [[nodiscard]] auto getRace() const -> std::vector<std::string>;

    friend auto operator<<(std::ostream & /*out*/, const Race & /*race*/) -> std::ostream &;
};

#endif
