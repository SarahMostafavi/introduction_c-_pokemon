//
// Created by 33651 on 14/09/2026.
//

#include "../inc/InfoConsole.h"
#include <iostream>

using std::cout;
using std::endl;

void InfoConsole::displayInfo(const Pokemon &pokemon) {
    cout << "---- Info du pokemon " << pokemon.getName() << " ----" << endl;
    cout << "Id : " << pokemon.getId() << endl;
    cout << "Evolution : " << pokemon.getEvolution() << endl;
    cout << "PV max : " << pokemon.getHitPointMax() << endl;
    cout << "PV : " << pokemon.getHitPoint() << endl;
    cout << "Attaque : " << pokemon.getAttack() << endl;
    cout << "Defense : " << pokemon.getDefense() << endl;
    cout << "Generation : " << pokemon.getGeneration() << endl;
    cout << "----  Fin info ----" << endl;
}

void InfoConsole::displayAttackSuccessInfo(bool isAttackSuccessful, const Pokemon &attacker, const Pokemon &defender) {
    cout << attacker.getName() << " attaque " << defender.getName() <<"." << endl;
    if (!isAttackSuccessful) {
        cout << defender.getName() << " esquive." << endl;
    }
}

void InfoConsole::displaySuccessfulAttackInfo(bool isAttackFatal, const Pokemon &attacker, const Pokemon &defender, double damageInflicted) {
    cout << defender.getName() << " subit " << damageInflicted <<" degats." << endl;
    cout << defender.getName() << " a " << defender.getHitPoint() <<" PV." << endl;
    if (isAttackFatal) {
        cout << attacker.getName() << " a tue " << defender.getName() <<"." << endl;
        cout << attacker.getName() << " a gagne." << endl;
    }
}

void InfoConsole::displayHealInfo(const Pokemon &pokemon, double amountToHeal) {
    cout << pokemon.getName() << " se soigne de " << amountToHeal <<" degats." << endl;
    cout << pokemon.getName() << " a " << pokemon.getHitPoint() <<" PV." << endl;
}
