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
    Pokemon* activePokemon;
    int numberOfPokeballs;
    int numberOfHealPotion;
    const int MAX_HIT_POINTS_FOR_POKEBALL_EFFICIENCY = 20;
    const int NUMBER_OF_HIT_POINTS_HEALED_BY_POTION = 20;

    public:
    Player();

    PokemonParty& getParty();
    PokemonTeam& getTeam();
    int getNumberOfPokeballs() const;
    int getNumberOfHealPotion() const;

    /**
     * Give numberOfPokeballs additional pokeballs to the player
     * @param numberOfPokeballs
     */
    void addAdditionalPokeballs(int numberOfPokeballs);

    /**
     * Give numberOfHealPotion additional heal potion to the player
     * @param numberOfHealPotion
     */
    void addAdditionalHealPotion(int numberOfHealPotion);

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
     * @return true if the player has at least one pokeball
     */
    bool hasPokeballs() const;

    /**
     * Use one heal potion on the active pokemon.
     * @return if a heal potion is used or not
     */
    bool useHealPotionOn();

    /**
     * Says if the player has an heal potion.
     * @return true if the player has at least one heal potion
     */
    bool hasHealPotion() const;
};


#endif //TICTACTOE_PLAYER_H
