//
// Created by 33651 on 20/09/2026.
//

#include "../inc/PokemonTeam.h"

#include <stdexcept>

PokemonTeam::PokemonTeam() {
    arrayOfPokemon.resize(6);
}

void PokemonTeam::putPokemonFromPokemonPartyInPosition(const Pokemon &pokemon, PokemonParty& pokemonParty, int position) {
    if (position>=0 && position<6) {
        if (arrayOfPokemon.at(position) != nullptr) {
            sendPokemonToPokemonParty(*arrayOfPokemon.at(position), pokemonParty);
            removePokemonAtPositionFromTheTeam(position);
        }
        arrayOfPokemon.at(position) = new Pokemon(pokemon);
    }
    else {
        throw std::out_of_range("La position n° "+std::to_string(position)+" n'existe pas. Elle doit etre entre 0 et 5.");
    }
}

void PokemonTeam::removePokemonAtPositionFromTheTeam(int position){
    delete arrayOfPokemon.at(position);
    arrayOfPokemon.at(position) = nullptr;
}

void PokemonTeam::sendPokemonToPokemonParty(const Pokemon &pokemon, PokemonParty& pokemonParty) {
    pokemonParty.addPokemon(pokemon);
}

Pokemon PokemonTeam::getPokemonById(int id) {
    for (Pokemon* pokemonToGet : arrayOfPokemon) {
        if (pokemonToGet != nullptr && id == pokemonToGet->getId()) {
            return Pokemon(*pokemonToGet);
        }
    }
    // Exception si le pokémon n'est pas dans la pokemonParty.
    throw std::invalid_argument("Vous ne possédez pas le pokemon d'id " + std::to_string(id) +".");
}

Pokemon PokemonTeam::getPokemonByName(string name) {
    for (Pokemon* pokemonToGet : arrayOfPokemon) {
        if (pokemonToGet != nullptr && pokemonToGet->getName() == name) {
            return *pokemonToGet;
        }
    }
    throw std::invalid_argument("Vous ne possédez pas le pokemon " + name + ".");
}


