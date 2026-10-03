//
// Created by 33651 on 03/10/2026.
//

#include "../inc/Player.h"

Player::Player(): party(), team() {
    numberOfPokeballs = 0;
}

PokemonParty & Player::getParty() {
    return party;
}

PokemonTeam & Player::getTeam() {
    return team;
}

int Player::getNumberOfPokeballs() const {
    return numberOfPokeballs;
}

bool Player::isThePokemonCaptured(const Pokemon &opponentPokemon) const {
    return (opponentPokemon.getHitPoint() < maxHitPointsForPokeballEfficiency);
}



bool Player::useOnePokeballOn(const Pokemon &opponentPokemon) {
    if (hasPokeballs()) {
        numberOfPokeballs--;
        std::cout << "Vous utilisez une pokeball sur " << opponentPokemon.getName() <<"." << std::endl;
        if (isThePokemonCaptured(opponentPokemon)) {
            party.addPokemon(opponentPokemon);
            std::cout << "Vous avez capturé " << opponentPokemon.getName() << "." << std::endl;
        }
        else {
            std::cout << opponentPokemon.getName() << " esquive." << std::endl;
        }
        return true;
    }
    std::cerr << "Vous n'avez plus de Pokeballs. Choisissez une autre action." << std::endl;
    return false;
}

bool Player::hasPokeballs() const {
    return (numberOfPokeballs > 0);
}
