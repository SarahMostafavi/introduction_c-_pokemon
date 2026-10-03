//
// Created by 33651 on 14/09/2026.
//

#include "../../inc/pokemon/Pokemon.h"
#include "../../inc/pokemon/InfoConsolePokemon.h"

int Pokemon::numberOfPokemons = 0;

Pokemon::Pokemon(int id, const string &name, double hitPointMax,
    double hitPoint, double attack, double defense) :
    id(id), name(name), hitPointMax(hitPointMax), hitPoint(hitPoint),
    attack(attack), defense(defense) {
        numberOfPokemons ++;
}

Pokemon::Pokemon(const Pokemon &anotherPokemon) : id(anotherPokemon.id),name(anotherPokemon.name),
    hitPointMax(anotherPokemon.hitPointMax), hitPoint(anotherPokemon.hitPoint),attack(anotherPokemon.attack),
    defense(anotherPokemon.defense) {
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

int Pokemon::getNumberOfPokemons() {
    return numberOfPokemons;
}

void Pokemon::attackPokemon(Pokemon &anotherPokemon) const{
    const bool isAttackSuccessful = (attack > anotherPokemon.defense);
    InfoConsolePokemon::displayAttackSuccessInfo(isAttackSuccessful, *this, anotherPokemon);
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
    InfoConsolePokemon::displaySuccessfulAttackInfo(isAttackFatal, *this,anotherPokemon, damage);

    return isAttackFatal;
}

void Pokemon::healOf(double amountToHeal) {
    if (amountToHeal > 0) {
        hitPoint += amountToHeal;
        if (hitPoint > hitPointMax) {
            hitPoint = hitPointMax;
        }
        InfoConsolePokemon::displayHealInfo(*this, amountToHeal);
    }
}


