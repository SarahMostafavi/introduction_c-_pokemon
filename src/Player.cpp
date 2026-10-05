//
// Created by 33651 on 03/10/2026.
//

#include "../inc/Player.h"

Player::Player(): party(), team() {
    activePokemonPosition = -1;
    numberOfPokeballs = 0;
    numberOfHealPotion = 0;
}

PokemonParty & Player::getParty() {
    return party;
}

PokemonTeam & Player::getTeam() {
    return team;
}

Pokemon& Player::getActivePokemon() {
    return *team.getPokemonAtPosition(activePokemonPosition);
}

int Player::getNumberOfPokeballs() const {
    return numberOfPokeballs;
}

int Player::getNumberOfHealPotion() const {
    return numberOfHealPotion;
}

void Player::changeActivePokemonByPokemonAtIndex(int position) {
    if (team.isPositionValid(position) && !team.getPokemonAtPosition(position)->isPokemonDead()) {
        activePokemonPosition = position;
    }
}

void Player::addAdditionalPokeballs(int numberOfAdditionalPokeballs) {
    numberOfPokeballs += numberOfAdditionalPokeballs;
}

void Player::addAdditionalHealPotion(int numberOfAdditionalHealPotion) {
    numberOfHealPotion += numberOfAdditionalHealPotion;
}

bool Player::isThePokeballEfficient(const Pokemon &opponentPokemon) const {
    return (opponentPokemon.getHitPoint() < MAX_HIT_POINTS_FOR_POKEBALL_EFFICIENCY);
}

bool Player::useOnePokeballOn(const Pokemon &opponentPokemon) {
    if (hasPokeballs()) {
        numberOfPokeballs--;
        std::cout << "Vous utilisez une pokeball sur " << opponentPokemon.getName() <<"." << std::endl;
        if (isThePokeballEfficient(opponentPokemon)) {
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

bool Player::useHealPotion() {
    if (hasHealPotion()) {
        numberOfHealPotion--;
        getActivePokemon().healOf(NUMBER_OF_HIT_POINTS_HEALED_BY_POTION);
        return true;
    }
    return false;
}

bool Player::hasHealPotion() const {
    return (numberOfHealPotion > 0);
}
