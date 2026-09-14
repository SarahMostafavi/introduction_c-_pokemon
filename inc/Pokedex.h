//
// Created by 33651 on 14/09/2026.
//

#ifndef TICTACTOE_POKEDEX_H
#define TICTACTOE_POKEDEX_H
#include "SetOfPokemon.h"


class Pokedex : public SetOfPokemon{
    private:
    static Pokedex* pinstance;
    Pokedex(std::pmr::string fileName);
    static vector<string> arrayOfPokemonNames;

    public:
    static Pokedex *getInstance(const std::pmr::string& fileName);
    Pokemon getPokemonById(int id) override;

    Pokemon getPokemonByName(string name) override;
};


#endif //TICTACTOE_POKEDEX_H
