//
// Created by 33651 on 14/09/2026.
//

#ifndef TICTACTOE_POKEDEX_H
#define TICTACTOE_POKEDEX_H
#include "SetOfPokemon.h"

/**
 * The class contains all the pokemon and allows to get a copy of a pokemon given his name or id.
 */
class Pokedex : public SetOfPokemon{
    private:
    static Pokedex* pinstance;
    static vector<string> arrayOfPokemonNames;
    Pokedex(string fileName);

    public:
    /**
     * Initialize the pokedex from the file and the array of pokemon names possible.
     * @param fileName
     */
    static Pokedex*  getInstance(const string& fileName);

    /**
     * Create a copy of the pokemon associated to the id given.
     * @param id
     * @return
     */
    Pokemon getPokemonById(int id) override;

    /**
     * Create a copy of the pokemon associated to the name given.
     * @param name
     * @return
     */
    Pokemon getPokemonByName(string name) override;
};


#endif //TICTACTOE_POKEDEX_H
