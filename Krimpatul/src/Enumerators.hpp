#ifndef ENUMERATORS_HPP
#define ENUMERATORS_HPP

enum class RaceEnum
{
    DWARF,
    ELF,
    GNOME,
    HALFLING,
    HALF_ELF,
    HALF_ORC,
    HUMAN
};

enum class AbilitiesEnum
{
    STR = 0,
    DEX = 1,
    CON = 2,
    INT = 3,
    WIS = 4,
    CHA = 5
};

enum class AlignEnum
{
    LAWFUL_GOOD,
    NEUTRAL_GOOD,
    CHAOTIC_GOOD,
    LAWFUL_NEUTRAL,
    NEUTRAL,
    CHAOTIC_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_EVIL,
    CHAOTIC_EVIL
};

enum class ClassEnum
{
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

enum class SizeEnum
{
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

#endif
