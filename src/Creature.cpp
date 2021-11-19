#include "Creature.hpp"

Creature::Creature(std::vector<std::string_view> list_race,
                   std::vector<std::string_view> list_class)
    : m_race{list_race}, m_class{list_class}
{
    init();
}

auto Creature::init() -> void
{
    if(m_race.getRace().at(0) == "Dwarf")
    {
        m_abilities["Constitution"] += 2;
        if(m_race.getRace().at(1) == "Hill Dwarf")
        {
            m_abilities["Wisdom"] += 1;
        }
        else
        {
            m_abilities["Strength"] += 2;
        }
    }
    else if(m_race.getRace().at(0) == "Dragonborn")
    {
        m_abilities["Strength"] += 2;
        m_abilities["Charisma"] += 1;
    }
    else if(m_race.getRace().at(0) == "Elf")
    {
        m_abilities["Dexterity"] += 2;
        if(m_race.getRace().at(1) == "Dark Elf")
        {
            m_abilities["Charisma"] += 1;
        }
        else if(m_race.getRace().at(1) == "High Elf")
        {
            m_abilities["Intelligence"] += 1;
        }
        else
        {
            m_abilities["Wisdom"] += 1;
        }
    }
    else if(m_race.getRace().at(0) == "Gnome")
    {
        m_abilities["Intelligence"] += 2;
        if(m_race.getRace().at(1) == "Forest Gnome")
        {
            m_abilities["Dexterity"] += 1;
        }
        else
        {
            m_abilities["Constitution"] += 1;
        }
    }
    else if(m_race.getRace().at(0) == "Halfling")
    {
        m_abilities["Dexterity"] += 2;
        if(m_race.getRace().at(1) == "Lightfoot Halfling")
        {
            m_abilities["Charisma"] += 1;
        }
        else
        {
            m_abilities["Constitution"] += 1;
        }
    }
    else if(m_race.getRace().at(0) == "Half-Elf")
    {
        m_abilities["Charisma"] += 2;
    }
    else if(m_race.getRace().at(0) == "Half-Orc")
    {
        m_abilities["Strength"] += 2;
        m_abilities["Constitution"] += 1;
    }
    else if(m_race.getRace().at(0) == "Human")
    {
        m_abilities["Strength"] += 1;
        m_abilities["Dexterity"] += 1;
        m_abilities["Constitution"] += 1;
        m_abilities["Intelligence"] += 1;
        m_abilities["Wisdom"] += 1;
        m_abilities["Charisma"] += 1;
    }
    else if(m_race.getRace().at(0) == "Tiefling")
    {
        m_abilities["Intelligence"] += 1;
        m_abilities["Charisma"] += 2;
    }
}

auto operator<<(std::ostream &out, const Creature &creature) -> std::ostream &
{
    out << creature.m_race << " " << creature.m_class;
    return out;
}
