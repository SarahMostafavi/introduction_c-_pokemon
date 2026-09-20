//
// Created by 33651 on 18/09/2026.
//

#include "../inc/PokemonParty.h"

#include <stdexcept>

PokemonParty::PokemonParty(){}

void PokemonParty::addPokemon(const Pokemon& pokemon) {
    arrayOfPokemon.push_back(new Pokemon(pokemon));
}

void PokemonParty::removePokemon(const Pokemon &pokemon) {
    for (int i = 0; i < arrayOfPokemon.size(); i++) {
        if (arrayOfPokemon.at(i)->getName() == pokemon.getName()) {
            delete arrayOfPokemon.at(i);
            arrayOfPokemon.erase(arrayOfPokemon.begin() + i);
            break;
        }
    }
}

int PokemonParty::getNumberOfPokemonInPokemonParty() const {
    return arrayOfPokemon.size();
}

Pokemon PokemonParty::getPokemonById(int id) {
    return *arrayOfPokemon.at(id);
}

Pokemon PokemonParty::getPokemonByName(string name) {
    for (Pokemon* pokemonToGet : arrayOfPokemon) {
        if (pokemonToGet->getName() == name) {
            return *pokemonToGet;
        }
    }
    throw std::invalid_argument("Vous ne possédez pas le pokemon " + name + ".");
}

