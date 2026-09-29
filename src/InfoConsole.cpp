//
// Created by 33651 on 14/09/2026.
//

#include "../inc/InfoConsole.h"
#include <iostream>

using std::cout;
using std::endl;

void InfoConsole::displayInfo(const Pokemon &pokemon) {
    cout <<"    " << "Name              :   " << pokemon.getName() << endl;
    cout <<"    " << "Id                :   " << pokemon.getId() << endl;
    cout <<"    " << "PV / PV_max       :   " << pokemon.getHitPoint() << " / " << pokemon.getHitPointMax() << endl;
    cout <<"    " << "Attaque / Defense :   " << pokemon.getAttack() << " / " << pokemon.getDefense() << endl;
}

void InfoConsole::displayAttackSuccessInfo(bool isAttackSuccessful, const Pokemon &attacker, const Pokemon &defender) {
    cout << "\n >>>" << attacker.getName() << " attaque " << defender.getName() <<"." << endl;
    if (!isAttackSuccessful) {
        cout << "    " << defender.getName() << " esquive." << endl;
    }
}

void InfoConsole::displaySuccessfulAttackInfo(bool isAttackFatal, const Pokemon &attacker, const Pokemon &defender, double damageInflicted) {
    cout << "    "<< defender.getName() << " subit " << damageInflicted <<" degats." << endl;
    cout << "    "<< defender.getName() << " a " << defender.getHitPoint() <<" PV." << endl;
    if (isAttackFatal) {
        cout << "    "<< attacker.getName() << " a tue " << defender.getName() <<"." << endl;
        cout << "    "<< attacker.getName() << " a gagne.\n" << endl;
    }
}

void InfoConsole::displayHealInfo(const Pokemon &pokemon, double amountToHeal) {
    cout << pokemon.getName() << " se soigne de " << amountToHeal <<" degats." << endl;
    cout << pokemon.getName() << " a " << pokemon.getHitPoint() <<" PV." << endl;
}

void InfoConsole::displayPokemonAddedInThePartyMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " a ete envoye dans la pokemonParty." << endl;
}

void InfoConsole::displayPokemonRemovedFromThePartyMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " est appele depuis la pokemonParty." << endl;
}

void InfoConsole::displayPokemonAddedInTheTeamMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " rejoint votre equipe." << endl;
}

void InfoConsole::displayPokemonAtPositionInTheTeamInfo(const Pokemon *pokemon, const int position) {
    if (position ==0) {
        cout <<"----------------- Equipe -----------------" << endl;
    }

    cout << "[" << position+1 << "]" << endl;
    if (pokemon != nullptr) {
        displayInfo(*pokemon);
    }
    else {
        cout << "    Emplacement vide !" << endl;
    }
    if (position == 5) {
        cout <<"------------- Fin Equipe -----------------" << endl;
    }
}
