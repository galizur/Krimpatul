#ifndef PLAYERCHARACTER_HPP
#define PLAYERCHARACTER_HPP

#include "Enumerators.hpp"
#include "krpch.hpp"

#include "Race.hpp"
#include "CClass.hpp"
#include "Alignment.hpp"
#include "BaseCharacter.hpp"

class PlayerCharacter : public BaseCharacter
{
public:
    /* Constructors */
    PlayerCharacter(RaceEnum /*race*/, ClassEnum /*cclass*/, AlignEnum /*align*/);
    PlayerCharacter(RaceEnum /*race*/, ClassEnum /*cclass*/, AlignEnum /*align*/,
                    std::string /*char_name*/, std::string /*player_name*/);
    ~PlayerCharacter() override              = default;
    PlayerCharacter(const PlayerCharacter &) = delete;
    auto operator=(const PlayerCharacter &) -> PlayerCharacter & = delete;
    PlayerCharacter(PlayerCharacter &&)                          = delete;
    auto operator=(PlayerCharacter &&) -> PlayerCharacter & = delete;
    /******************/
    /* Setters */
    auto setNameChar(std::string /*name_char*/) -> void;
    auto setNamePlayer(std::string /*name_player*/) -> void;
    /******************/
    /* Getters */
    [[nodiscard]] auto getNameChar() const -> std::string;
    [[nodiscard]] auto getNamePlayer() const -> std::string;
    /******************/
private:
    std::string m_name_char{"Unset"};
    std::string m_name_player{"Unset"};
};

#endif
