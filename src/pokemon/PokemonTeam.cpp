//
// Created by 33651 on 20/09/2026.
//

#include "../../inc/pokemon/PokemonTeam.h"

#include <stdexcept>

PokemonTeam::PokemonTeam() {
    arrayOfPokemon.resize(6);
}

void PokemonTeam::putPokemonFromPokemonPartyInPosition(const Pokemon &pokemon, PokemonParty& pokemonParty, int position) {
    if (!isPositionValid(position)) {
        throw std::out_of_range("La position n° "+std::to_string(position)+" n'existe pas. Elle doit etre entre 0 et 5.");
    }
    else if (!pokemonParty.isPokemonInThePokemonParty(pokemon)) {
        throw std::out_of_range("Le pokemon à ajouter "+ pokemon.getName() +" n'est pas dans la pokemon party");

    }
    else {
        if (arrayOfPokemon.at(position) != nullptr) {
            sendPokemonToPokemonParty(*arrayOfPokemon.at(position), pokemonParty);
            removePokemonAtPositionFromTheTeam(position);
        }
        arrayOfPokemon.at(position) = new Pokemon(pokemon);
        pokemonParty.removePokemon(pokemon);
        InfoConsolePokemon::displayPokemonAddedInTheTeamMessage(pokemon);
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
            return *pokemonToGet;
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

Pokemon * PokemonTeam::getPokemonAtPosition(int position) const {
    if (!isPositionValid(position)) {
        throw std::out_of_range("La position n° "+std::to_string(position)+" n'existe pas. Elle doit etre entre 0 et 5.");
    }

    if (arrayOfPokemon.at(position) == nullptr) {
        throw std::out_of_range("L'emplacement ["+std::to_string(position)+"] est vide.");
    }
    return arrayOfPokemon.at(position);
}

bool PokemonTeam::isPositionValid(int position) {
    return position>=0 && position<6;
}

bool PokemonTeam::areAllPokemonInTeamDead() const {
    for (int i = 0; i < 6; ++i) {
        if (arrayOfPokemon[i] != nullptr && !arrayOfPokemon[i]->isPokemonDead()) {
            return false;
        }
    }
    return true;           }

void PokemonTeam::healAllPokemon() const {
    for (Pokemon* pokemon : arrayOfPokemon) {
        if (pokemon != nullptr) {
            pokemon->healOf(pokemon->getHitPointMax());
        }
    }
    InfoConsolePokemon::healAllPokemonOfTheTeam();
}

void PokemonTeam::displayInfoTeam() const {
    int position = 0;
    for (const Pokemon* pokemon : arrayOfPokemon) {
        InfoConsolePokemon::displayPokemonAtPositionInTheTeamInfo(pokemon,position);
        position++;
    }
}

