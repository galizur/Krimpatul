#include "krpch.hpp"
#include "BaseCharacter.hpp"

// Setters
auto BaseCharacter::setClasses(const Classes classes) -> void
{
    m_class = classes;
}
auto BaseCharacter::setRaces(const Races races) -> void
{
    m_race = races;
}
auto BaseCharacter::setSizes(const Sizes sizes) -> void
{
    m_size = sizes;
}
auto BaseCharacter::setEyes(const Colors eyes) -> void
{
    m_color_eyes = eyes;
}
auto BaseCharacter::setHair(const Colors hair) -> void
{
    m_color_hair = hair;
}
auto BaseCharacter::setSkin(const Colors skin) -> void
{
    m_color_skin = skin;
}
auto BaseCharacter::setHeight(const unsigned short feet,
                              const unsigned short inches) -> void
{
    m_height = std::make_tuple(feet, inches);
}
auto BaseCharacter::setWeight(const unsigned int weight) -> void
{
    m_weight = weight;
}
auto BaseCharacter::setAge(const unsigned int age) -> void
{
    m_age = age;
}
auto BaseCharacter::setGender(const bool gender) -> void
{
    m_gender = gender;
}
auto BaseCharacter::setSpeed(const unsigned short speed) -> void
{
    m_speed = speed;
}
auto BaseCharacter::setDeities(const Deities deities) -> void
{
    m_deity = deities;
}
auto BaseCharacter::setAlignments(const Alignments alignment) -> void
{
    m_alignment = alignment;
}
auto BaseCharacter::setLevel(const unsigned short level) -> void
{
    m_level = level;
}
// Getters
auto BaseCharacter::getClasses() const -> Classes
{
    return m_class;
}
auto BaseCharacter::getRaces() const -> Races
{
    return m_race;
}
auto BaseCharacter::getSizes() const -> Sizes
{
    return m_size;
}
auto BaseCharacter::getEyes() const -> Colors
{
    return m_color_eyes;
}
auto BaseCharacter::getHair() const -> Colors
{
    return m_color_hair;
}
auto BaseCharacter::getSkin() const -> Colors
{
    return m_color_skin;
}
auto BaseCharacter::getHeight() const
    -> std::tuple<const unsigned short, const unsigned short>
{
    return m_height;
}
auto BaseCharacter::getWeight() const -> unsigned int
{
    return m_weight;
}
auto BaseCharacter::getAge() const -> unsigned int
{
    return m_age;
}
auto BaseCharacter::getGender() const -> bool
{
    return m_gender;
}
auto BaseCharacter::getSpeed() const -> unsigned short
{
    return m_speed;
}
auto BaseCharacter::getDeities() const -> Deities
{
    return m_deity;
}
auto BaseCharacter::getAlignments() const -> Alignments
{
    return m_alignment;
}
auto BaseCharacter::getLevel() const -> unsigned short
{
    return m_level;
}
// To string
auto BaseCharacter::classesToString(const Classes classes) const -> std::string
{
    switch(classes)
    {
    case Classes::BARBARIAN: return "Barbarian"; break;
    case Classes::BARD: return "Bard"; break;
    case Classes::CLERIC: return "Cleric"; break;
    case Classes::DRUID: return "Druid"; break;
    case Classes::FIGHTER: return "Fighter"; break;
    case Classes::MONK: return "Monk"; break;
    case Classes::PALADIN: return "Paladin"; break;
    case Classes::RANGER: return "Ranger"; break;
    case Classes::ROGUE: return "Rogue"; break;
    case Classes::SORCERER: return "Sorcerer"; break;
    case Classes::WIZARD: return "Wizard"; break;
    case Classes::INVALID:
    default: return "INVALID"; break;
    }
}

auto BaseCharacter::racesToString(const Races races) const -> std::string
{
    switch(races)
    {
    case Races::DWARF: return "Dwarf"; break;
    case Races::ELF: return "Elf"; break;
    case Races::GNOME: return "Gnome"; break;
    case Races::HALF_ELF: return "Half-elf"; break;
    case Races::HALF_ORC: return "Half-orc"; break;
    case Races::HALFLING: return "Halfling"; break;
    case Races::HUMAN: return "Human"; break;
    case Races::INVALID:
    default: return "INVALID"; break;
    }
}

auto BaseCharacter::sizesToString(const Sizes sizes) const -> std::string
{
    switch(sizes)
    {
    case Sizes::FINE: return "Fine"; break;
    case Sizes::DIMINUTIVE: return "Diminutive"; break;
    case Sizes::TINY: return "Tiny"; break;
    case Sizes::SMALL: return "Small"; break;
    case Sizes::MEDIUM: return "Medium"; break;
    case Sizes::LARGE_TALL: return "Large (Tall)"; break;
    case Sizes::LARGE_LONG: return "Large (Long)"; break;
    case Sizes::HUGE_TALL: return "Huge (Tall)"; break;
    case Sizes::HUGE_LONG: return "Huge (Long)"; break;
    case Sizes::GARGANTUAN_TALL: return "Gargantuan (Tall)"; break;
    case Sizes::GARGANTUAN_LONG: return "Gargantuan (Long)"; break;
    case Sizes::COLOSSAL_TALL: return "Colossal (Tall)"; break;
    case Sizes::COLOSSAL_LONG: return "Colossal (Long)"; break;
    case Sizes::INVALID:
    default: return "INVALID"; break;
    }
}

auto BaseCharacter::colorsToString(const Colors colors) const -> std::string
{
    switch(colors)
    {
    case Colors::AQUA: return "Aqua"; break;
    case Colors::AQUAMARINE: return "Aquamarine"; break;
    case Colors::AZURE: return "Azure"; break;
    case Colors::BEIGE: return "Beige"; break;
    case Colors::BLACK: return "Black"; break;
    case Colors::BLOND: return "Blond"; break;
    case Colors::BLUE: return "Blue"; break;
    case Colors::BROWN: return "Brown"; break;
    case Colors::CHESTNUT: return "Chestnut"; break;
    case Colors::COPPER: return "Copper"; break;
    case Colors::DARK_GREEN: return "Dark Green"; break;
    case Colors::DARK_RED: return "Dark Red"; break;
    case Colors::RED: return "Red"; break;
    case Colors::WHITE: return "White"; break;
    case Colors::GREEN: return "Green"; break;
    case Colors::HAZEL: return "Hazel"; break;
    case Colors::NAVY_BLUE: return "Navy Blue"; break;
    case Colors::GRAY: return "Gray"; break;
    case Colors::INVALID:
    default: return "INVALID"; break;
    }
}

auto BaseCharacter::deitiesToString(const Deities deities) const -> std::string
{
    switch(deities)
    {
    case Deities::NONE: return "None"; break;
    case Deities::BOCCOB: return "Boccob"; break;
    case Deities::CORELLON_LARETHIAN: return "Corellon Larethian"; break;
    case Deities::EHLONNA: return "Ehlonna"; break;
    case Deities::ERYTHNUL: return "Erythnul"; break;
    case Deities::FHARLANGHN: return "Fharlanghn"; break;
    case Deities::GARL_GLITTERGOLD: return "Garl Glittergold"; break;
    case Deities::GRUUMSH: return "Gruumsh"; break;
    case Deities::HEIRONEOUS: return "Heironeous"; break;
    case Deities::HEXTOR: return "Hextor"; break;
    case Deities::KORD: return "Kord"; break;
    case Deities::MORADIN: return "Moradin"; break;
    case Deities::NERULL: return "Nerull"; break;
    case Deities::OBAD_HAI: return "Obad-Hai"; break;
    case Deities::OLIDAMMARA: return "Olidammara"; break;
    case Deities::PELOR: return "Pelor"; break;
    case Deities::ST_CUTHBERT: return "St. Cuthbert"; break;
    case Deities::VECNA: return "Vecna"; break;
    case Deities::WEE_JAS: return "Wee Jas"; break;
    case Deities::YONDALLA: return "Yondalla"; break;
    case Deities::INVALID:
    default: return "INVALID"; break;
    }
}

auto BaseCharacter::alignmentsToString(const Alignments alignments) const
    -> std::string
{
    switch(alignments)
    {
    case Alignments::LAWFUL_GOOD: return "Lawful Good"; break;
    case Alignments::NEUTRAL_GOOD: return "Neutral Good"; break;
    case Alignments::CHAOTIC_GOOD: return "Chaotic Good"; break;
    case Alignments::LAWFUL_NEUTRAL: return "Lawful Neutral"; break;
    case Alignments::TRUE_NEUTRAL: return "True Neutral"; break;
    case Alignments::CHAOTIC_NEUTRAL: return "Chaotic Neutral"; break;
    case Alignments::LAWFUL_EVIL: return "Lawful Evil"; break;
    case Alignments::NEUTRAL_EVIL: return "Neutral Evil"; break;
    case Alignments::CHAOTIC_EVIL: return "Chaotic Evil"; break;
    case Alignments::INVALID:
    default: return "INVALID"; break;
    }
}
