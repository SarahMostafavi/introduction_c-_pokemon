//
// Created by 33651 on 14/09/2026.
//

#include "../../inc/pokemon/InfoConsolePokemon.h"
#include <iostream>

using std::cout;
using std::endl;

void InfoConsolePokemon::displayInfo(const Pokemon &pokemon) {
    cout <<"    " << "Name              :   " << pokemon.getName() << endl;
    cout <<"    " << "Id                :   " << pokemon.getId() << endl;
    cout <<"    " << "PV / PV_max       :   " << pokemon.getHitPoint() << " / " << pokemon.getHitPointMax() << endl;
    cout <<"    " << "Attaque / Defense :   " << pokemon.getAttack() << " / " << pokemon.getDefense() << endl;
}

void InfoConsolePokemon::displayAttackSuccessInfo(bool isAttackSuccessful, const Pokemon &attacker, const Pokemon &defender) {
    cout << "\n >>>" << attacker.getName() << " attaque " << defender.getName() <<"." << endl;
    if (!isAttackSuccessful) {
        cout << "    " << defender.getName() << " esquive." << endl;
    }
}

void InfoConsolePokemon::displaySuccessfulAttackInfo(bool isAttackFatal, const Pokemon &attacker, const Pokemon &defender, double damageInflicted) {
    cout << "    "<< defender.getName() << " subit " << damageInflicted <<" degats." << endl;
    cout << "    "<< defender.getName() << " a " << defender.getHitPoint() <<" PV." << endl;
    if (isAttackFatal) {
        cout << "    "<< attacker.getName() << " a tue " << defender.getName() <<"." << endl;
        cout << "    "<< attacker.getName() << " a gagne.\n" << endl;
    }
}

void InfoConsolePokemon::displayHealInfo(const Pokemon &pokemon, double amountToHeal) {
    cout << pokemon.getName() << " se soigne de " << amountToHeal <<" degats." << endl;
    cout << pokemon.getName() << " a " << pokemon.getHitPoint() <<" PV." << endl;
}

void InfoConsolePokemon::displayPokemonAddedInThePartyMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " a ete envoye dans la pokemonParty." << endl;
}

void InfoConsolePokemon::displayPokemonRemovedFromThePartyMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " est appele depuis la pokemonParty." << endl;
}

void InfoConsolePokemon::displayPokemonAddedInTheTeamMessage(const Pokemon &pokemon) {
    cout << pokemon.getName() << " rejoint votre equipe." << endl;
}

void InfoConsolePokemon::displayPokemonAtPositionInTheTeamInfo(const Pokemon *pokemon, const int position) {
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

void InfoConsolePokemon::displayPokemonAtPositionInThePartyInfo(const Pokemon *pokemon, int positionInParty) {
    cout << "[" << positionInParty+1 << "]" << endl;
    displayInfo(*pokemon);

}

void InfoConsolePokemon::healAllPokemonOfTheTeam(){
    cout << "Tous les pokemons de l'equipe sont soignes." << endl;
}
