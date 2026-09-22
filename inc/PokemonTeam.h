//
// Created by 33651 on 20/09/2026.
//

#ifndef TICTACTOE_POKEMONATTACK_H
#define TICTACTOE_POKEMONATTACK_H
#include "SetOfPokemon.h"
#include "PokemonParty.h"

/**
 * Contains the team of 6 pokemons used during fight.
 * It is possible to put a pokemon in the team at a certain position, to send a pokemon to the pokemon party,
 * and to take a get a pokemon of the team given its id or name.
 */
class PokemonTeam : public SetOfPokemon{
    public:
    PokemonTeam();

    /**
     * Put a Pokemon in the team at position given.
     * If a pokemon was already at that position, it is sent back to PokemonParty.
     * @param pokemon 
     * @param pokemonParty
     * @param position
     */
    void putPokemonFromPokemonPartyInPosition(const Pokemon &pokemon, PokemonParty& pokemonParty, int position);

    /**
     * Remove the pokemon at position from the team.
     * @param position
     */
    void removePokemonAtPositionFromTheTeam(int position);

    /**
     * Send the pokemon to the pokemonParty
     * @param pokemon
     * @param pokemonParty
     */
    static void sendPokemonToPokemonParty(const Pokemon &pokemon, PokemonParty& pokemonParty);

    /**
     * Get the pokemon from the team of 6 pokemons if the id given is in the team.
     * @param id
     * @return
     */
    Pokemon getPokemonById(int id) override;

    /**
    * Get the pokemon from the team of 6 pokemons if the name given is in the team.
    * @param name
    * @return
    */
    Pokemon getPokemonByName(string name) override;
};


#endif //TICTACTOE_POKEMONATTACK_H
