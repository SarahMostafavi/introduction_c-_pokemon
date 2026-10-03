//
// Created by 33651 on 18/09/2026.
//

#ifndef TICTACTOE_POKEMONPARTY_H
#define TICTACTOE_POKEMONPARTY_H
#include "SetOfPokemon.h"
#include "InfoConsolePokemon.h"

/**
 * Represent the set of the pokemon owned by a person.
 * We can add or remove a pokemon of this set.
 */
class PokemonParty : public SetOfPokemon{
    public:
    PokemonParty();

    /**
     * Add the pokemon to the set of pokemon owned.
     * @param pokemon
     */
    void addPokemon(const Pokemon& pokemon);

    /**
     * Remove the pokemon of the set if the pokemon was in the set.
     * @param pokemon
     */
    void removePokemon(const Pokemon& pokemon);

    /**
     * Get the number of pokemon in PokemonParty.
     * @return the number of pokemon in PokemonParty
     */
    int getNumberOfPokemonInPokemonParty() const;

    /**
     * Get the pokemon from the set of pokemon owned if the id given is in the set.
     * @param id
     * @return
     */
    Pokemon getPokemonById(int id) override;

    /**
     * Get the pokemon from the set of pokemon owned if the name given is in the set.
     * @param name
     * @return
     */
    Pokemon getPokemonByName(string name) override;

    /**
     * Say if the pokemon is in the party
     * @param pokemonToCheck
     * @return bool
     */
    bool isPokemonInThePokemonParty(const Pokemon& pokemonToCheck) const;

};


#endif //TICTACTOE_POKEMONPARTY_H
