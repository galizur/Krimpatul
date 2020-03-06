#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum class Races
{
    INVALID = -1,
    DWARF,
    ELF,
    GNOME,
    HALF_ELF,
    HALF_ORC,
    HALFLING,
    HUMAN
};

enum class Classes
{
    INVALID = -1,
    BARBARIAN,
    BARD,
    CLERIC,
    DRUID,
    FIGHTER,
    MONK,
    PALADIN,
    RANGER,
    ROGUE,
    SORCERER,
    WIZARD
};

enum class Alignments
{
    INVALID = -1,
    LAWFUL_GOOD,
    NEUTRAL_GOOD,
    CHAOTIC_GOOD,
    LAWFUL_NEUTRAL,
    TRUE_NEUTRAL,
    CHAOTIC_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_EVIL,
    CHAOTIC_EVIL
};

enum class Deities
{
    INVALID = -1,
    NONE,
    BOCCOB,
    CORELLON_LARETHIAN,
    EHLONNA,
    ERYTHNUL,
    FHARLANGHN,
    GARL_GLITTERGOLD,
    GRUUMSH,
    HEIRONEOUS,
    HEXTOR,
    KORD,
    MORADIN,
    NERULL,
    OBAD_HAI,
    OLIDAMMARA,
    PELOR,
    ST_CUTHBERT,
    VECNA,
    WEE_JAS,
    YONDALLA
};

enum class Sizes
{
    INVALID = -1,
    FINE,
    DIMINUTIVE,
    TINY,
    SMALL,
    MEDIUM,
    LARGE_TALL,
    LARGE_LONG,
    HUGE_TALL,
    HUGE_LONG,
    GARGANTUAN_TALL,
    GARGANTUAN_LONG,
    COLOSSAL_TALL,
    COLOSSAL_LONG
};

// TODO: Add more colors
enum class Colors
{
    INVALID = -1,
    AQUA,
    AQUAMARINE,
    AZURE,
    BEIGE,
    BLACK,
    BLOND,
    BLUE,
    BROWN,
    CHESTNUT,
    COPPER,
    DARK_GREEN,
    DARK_RED,
    RED,
    WHITE,
    GREEN,
    HAZEL,
    NAVY_BLUE,
    GRAY
};

#endif // !ENUMS_HPP_
