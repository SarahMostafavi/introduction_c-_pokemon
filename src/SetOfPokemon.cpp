//
// Created by 33651 on 14/09/2026.
//

#include "../inc/SetOfPokemon.h"
#include "../inc/InfoConsole.h"
#include "../inc/Pokemon.h"

SetOfPokemon::~SetOfPokemon() {
    for (Pokemon* pokemon : arrayOfPokemon) {
        delete pokemon;
    }
}

void SetOfPokemon::displayListOfPokemonById(const vector<int>& ListOfPokemonId) {
    for (int id : ListOfPokemonId) {
        InfoConsole::displayInfo(getPokemonById(id));
    }
}

void SetOfPokemon::displayListOfPokemonByName(const vector<string>& ListOfPokemonName) {
    for (string name : ListOfPokemonName) {
        InfoConsole::displayInfo(getPokemonByName(name));
    }
}
