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

    virtual Pokemon getPokemonById(int id)=0;

    virtual Pokemon getPokemonByName(string name)=0;

    void displayListOfPokemonById(const vector<int>& ListOfPokemonId);

    void displayListOfPokemonByName(const vector<string> &ListOfPokemonName);

};


#endif //TICTACTOE_SETOFPOKEMON_H
