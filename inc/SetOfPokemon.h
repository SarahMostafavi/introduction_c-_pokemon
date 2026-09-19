//
// Created by 33651 on 14/09/2026.
//

#ifndef TICTACTOE_SETOFPOKEMON_H
#define TICTACTOE_SETOFPOKEMON_H


#include "Pokemon.h"
#include <vector>
using std::vector;


class SetOfPokemon {
    protected:
    vector<Pokemon*> arrayOfPokemon;
    public:
    virtual ~SetOfPokemon();

    /**
     * Find the pokemon associated to id in arrayOfPokemon.
     * @param id
     * @return the pokemon of id id
     */
    virtual Pokemon getPokemonById(int id) = 0;

    /**
     * Find the pokemon associated to name in arrayOfPokemon
     * @param name
     * @return the pokemon of name name
     */
    virtual Pokemon getPokemonByName(string name) = 0;

    /**
     * Display the info of each pokemon of ListOfPokemonId
     * @param ListOfPokemonId
     */
    void displayListOfPokemonById(const vector<int>& ListOfPokemonId);

    /**
    * Display the info of each pokemon of ListOfPokemonName
    * @param ListOfPokemonName
    */
    void displayListOfPokemonByName(const vector<string> &ListOfPokemonName);

};


#endif //TICTACTOE_SETOFPOKEMON_H
