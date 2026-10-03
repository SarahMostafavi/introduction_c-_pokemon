//
// Created by 33651 on 03/10/2026.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H
#include "pokemon/PokemonParty.h"
#include "pokemon/PokemonTeam.h"

/**
 * Represent the player.
 * The player has a party, a team of 6 pokemon and a number of pokeball.
 * The player can capture a pokemon.,
 */
class Player {
    private:
    PokemonParty party;
    PokemonTeam team;
    int numberOfPokeballs;
    const int maxHitPointsForPokeballEfficiency = 20;

    public:
    Player();

    PokemonParty& getParty();
    PokemonTeam& getTeam();
    int getNumberOfPokeballs() const;

    /**
     * Capture the pokemon if the pokeball is efficient and add it to the party.
     * @param opponentPokemon
     * @return true if the pokemon is captured, false otherwise
     */
    bool isThePokemonCaptured(const Pokemon &opponentPokemon) const;

    /**
     * Use a pokeball on the opponent pokemon and capture the pokemon
     * if the pokeball is efficient.
     * @param opponentPokemon
     * @return true if the pokeball is used.
     */
    bool useOnePokeballOn(const Pokemon &opponentPokemon);

    /**
     * Says if the player has a pokeball
     * @return true if the player has
     */
    bool hasPokeballs() const;
};


#endif //TICTACTOE_PLAYER_H
