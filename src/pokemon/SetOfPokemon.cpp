//
// Created by 33651 on 14/09/2026.
//

#include "../../inc/pokemon/SetOfPokemon.h"
#include "../../inc/pokemon/InfoConsolePokemon.h"
#include "../../inc/pokemon/Pokemon.h"

SetOfPokemon::~SetOfPokemon() {
    for (Pokemon* pokemon : arrayOfPokemon) {
        delete pokemon;
    }
}

void SetOfPokemon::displayListOfPokemonById(const vector<int>& ListOfPokemonId) {
    for (int id : ListOfPokemonId) {
        InfoConsolePokemon::displayInfo(getPokemonById(id));
    }
}

void SetOfPokemon::displayListOfPokemonByName(const vector<string>& ListOfPokemonName) {
    for (const string& name : ListOfPokemonName) {
        InfoConsolePokemon::displayInfo(getPokemonByName(name));
    }
}
