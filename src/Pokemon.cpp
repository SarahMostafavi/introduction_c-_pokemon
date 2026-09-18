//
// Created by 33651 on 14/09/2026.
//

#include "../inc/Pokemon.h"
#include "../inc/InfoConsole.h"
#include <iostream>
using std::cout;

int Pokemon::numberOfPokemons = 0;

Pokemon::Pokemon(int id, const string &name, int evolution, double hitPointMax,
    double hitPoint, double attack, double defense, int generation) :
    id(id), name(name), evolution(evolution), hitPointMax(hitPointMax), hitPoint(hitPoint),
    attack(attack), defense(defense), generation(generation) {
        numberOfPokemons ++;
}

Pokemon::Pokemon(const Pokemon &anotherPokemon) : id(anotherPokemon.id),name(anotherPokemon.name),
    evolution(anotherPokemon.evolution), hitPointMax(anotherPokemon.hitPointMax), hitPoint(anotherPokemon.hitPoint),
    attack(anotherPokemon.attack), defense(anotherPokemon.defense),generation(anotherPokemon.generation) {
        numberOfPokemons ++;
}

Pokemon::~Pokemon() {
    numberOfPokemons --;
}



int Pokemon::getId() const {
    return id;
}

string Pokemon::getName() const {
    return name;
}

int Pokemon::getEvolution() const {
    return evolution;
}

double Pokemon::getHitPointMax() const {
    return hitPointMax;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getGeneration() const {
    return generation;
}

int Pokemon::getNumberOfPokemons() {
    return numberOfPokemons;
}

void Pokemon::attackPokemon(Pokemon &anotherPokemon) const{
    const bool isAttackSuccessful = (attack > anotherPokemon.defense);
    InfoConsole::displayAttackSuccessInfo(isAttackSuccessful, *this, anotherPokemon);
    if (isAttackSuccessful) {
        bool isAttackFatal = this->inflictDamageOn(anotherPokemon);
    }
}

bool Pokemon::inflictDamageOn(Pokemon &anotherPokemon) const {
    const double damage = attack - anotherPokemon.defense;
    const bool isAttackFatal = (anotherPokemon.hitPoint <= damage);
    if (isAttackFatal){
        anotherPokemon.hitPoint = 0;
    }
    else {
        anotherPokemon.hitPoint -= damage;
    }
    InfoConsole::displaySuccessfulAttackInfo(isAttackFatal, *this,anotherPokemon, damage);

    return isAttackFatal;
}

void Pokemon::healOf(double amountToHeal) {
    if (amountToHeal > 0) {
        hitPoint += amountToHeal;
        if (hitPoint > hitPointMax) {
            hitPoint = hitPointMax;
        }
        InfoConsole::displayHealInfo(*this, amountToHeal);
    }
}


