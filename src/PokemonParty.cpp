//
// Created by 33651 on 18/09/2026.
//

#include "../inc/PokemonParty.h"

#include <stdexcept>

PokemonParty::PokemonParty(){}

void PokemonParty::addPokemon(const Pokemon& pokemon) {
    arrayOfPokemon.push_back(new Pokemon(pokemon));
    InfoConsole::displayPokemonAddedInThePartyMessage(pokemon);
}

void PokemonParty::removePokemon(const Pokemon &pokemon) {
    for (int i = 0; i < arrayOfPokemon.size(); i++) {
        if (arrayOfPokemon.at(i)->getName() == pokemon.getName()) {
            delete arrayOfPokemon.at(i);
            arrayOfPokemon.erase(arrayOfPokemon.begin() + i);
            InfoConsole::displayPokemonRemovedFromThePartyMessage(pokemon);
            break;
        }
    }
}

int PokemonParty::getNumberOfPokemonInPokemonParty() const {
    return arrayOfPokemon.size();
}

Pokemon PokemonParty::getPokemonById(int id) {
    for (Pokemon* pokemonToGet : arrayOfPokemon) {
        if (id == pokemonToGet->getId()) {
            return Pokemon(*pokemonToGet);
        }
    }
    // Exception si le pokémon n'est pas dans la pokemonParty.
    throw std::invalid_argument("Vous ne possédez pas le pokemon d'id " + std::to_string(id) +".");
}

Pokemon PokemonParty::getPokemonByName(string name) {
    for (Pokemon* pokemonToGet : arrayOfPokemon) {
        if (pokemonToGet->getName() == name) {
            return *pokemonToGet;
        }
    }
    // Exception si le pokémon n'est pas dans la pokemonParty.
    throw std::invalid_argument("Vous ne possédez pas le pokemon " + name + ".");
}

bool PokemonParty::isPokemonInThePokemonParty(const Pokemon &pokemonToCheck) const {
    bool isPokemonInTheParty = false;
    for (Pokemon* pokemon :arrayOfPokemon) {
        if (pokemon->getId() == pokemonToCheck.getId()) {
            isPokemonInTheParty = true;
        }
    }
    return isPokemonInTheParty;
}

