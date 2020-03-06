#ifndef BASE_CHARACTER_HPP_
#define BASE_CHARACTER_HPP_

#include "krpch.hpp"
#include "Enums.hpp"

class BaseCharacter
{
public:
    // Setters
    auto setClasses(const Classes) -> void;
    auto setRaces(const Races) -> void;
    auto setSizes(const Sizes) -> void;
    auto setEyes(const Colors) -> void;
    auto setHair(const Colors) -> void;
    auto setSkin(const Colors) -> void;
    auto setHeight(const unsigned short, const unsigned short) -> void;
    auto setWeight(const unsigned int) -> void;
    auto setAge(const unsigned int) -> void;
    auto setGender(const bool) -> void;
    auto setSpeed(const unsigned short) -> void;
    auto setDeities(const Deities) -> void;
    auto setAlignments(const Alignments) -> void;
    auto setLevel(const unsigned short) -> void;
    // Getters
    auto getClasses() const -> Classes;
    auto getRaces() const -> Races;
    auto getSizes() const -> Sizes;
    auto getEyes() const -> Colors;
    auto getHair() const -> Colors;
    auto getSkin() const -> Colors;
    auto getHeight() const
        -> std::tuple<const unsigned short, const unsigned short>;
    auto getWeight() const -> unsigned int;
    auto getAge() const -> unsigned int;
    auto getGender() const -> bool;
    auto getSpeed() const -> unsigned short;
    auto getDeities() const -> Deities;
    auto getAlignments() const -> Alignments;
    auto getLevel() const -> unsigned short;
    // To string
    auto classesToString(const Classes) const -> std::string;
    auto racesToString(const Races) const -> std::string;
    auto sizesToString(const Sizes) const -> std::string;
    auto colorsToString(const Colors) const -> std::string;
    auto deitiesToString(const Deities) const -> std::string;
    auto alignmentsToString(const Alignments) const -> std::string;
    // Helper functions
    auto convertFeetToMeters(std::tuple<unsigned short, unsigned short>)
        -> void;
    auto convertMetersToFeet(std::tuple<unsigned short, unsigned short>)
        -> void;

protected:
    BaseCharacter()          = default;
    virtual ~BaseCharacter() = default;

private:
    // Physical characteristics
    Classes m_class {Classes::INVALID};
    Races   m_race {Races::INVALID};
    Sizes   m_size {Sizes::INVALID};
    Colors  m_color_eyes {Colors::INVALID};
    Colors  m_color_hair {Colors::INVALID};
    Colors  m_color_skin {Colors::INVALID};
    // For now, we have our size in feet/inches
    // TODO: differentiate between feet and meters
    std::tuple<unsigned short, unsigned short> m_height {0, 0};
    unsigned int                               m_weight {0};
    unsigned int                               m_age {0};
    bool                                       m_gender {false};
    unsigned short                             m_speed {0};
    // Mental characteristics and misc
    Deities        m_deity {Deities::INVALID};
    Alignments     m_alignment {Alignments::INVALID};
    unsigned short m_level {1};
    // Ability scores
    std::array<short, 6> m_ability_score {0, 0, 0, 0, 0, 0};
    std::array<short, 6> m_ability_mod {0, 0, 0, 0, 0, 0};
    std::array<short, 6> m_ability_score_temp {0, 0, 0, 0, 0, 0};
    std::array<short, 6> m_ability_mod_temp {0, 0, 0, 0, 0, 0};
    // Saving throws
    short m_fortitude_max {0};
    short m_fortitude_base {0};
    short m_reflex_max {0};
    short m_reflex_base {0};
    short m_will_max {0};
    short m_will_base {0};
    // Hit points
    unsigned int m_hp_max {0};
    unsigned int m_hp_current {0};
    unsigned int m_hp_nonlethal {0};
    // Armor class
    unsigned short       m_ac_max {0};
    const unsigned short m_ac_base {10};
    unsigned short       m_ac_armor {0};
    unsigned short       m_ac_shield {0};
    unsigned short       m_ac_dex {0};
    unsigned short       m_ac_size {0};
    unsigned short       m_ac_natural {0};
    unsigned short       m_ac_deflection {0};
    unsigned short       m_ac_misc {0};
    unsigned short       m_ac_touch {0};
    unsigned short       m_ac_flat_footed {0};
    unsigned short       m_initiative {0};
    // Attributes
    unsigned short m_spell_resistance {0};
    unsigned short m_base_attack_bonus {0};
    unsigned short m_grapple {0};
    // TODO: add damage reduction and energy resistance
    // m_damage_reduction;
    // m_energy_resistance;
};

#endif    // !BASE_CHARACTER_HPP_
