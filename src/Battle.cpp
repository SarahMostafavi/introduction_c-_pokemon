//
// Created by 33651 on 04/10/2026.
//

#include "../inc/Battle.h"

using namespace std;

#include <limits>

Battle::Battle(Player &player, Pokemon &opponent):player(player), opponentPokemon(opponent), battleOutcome(BattleOutcome::NOT_ENDED) {
    cout << "----- Player VS " <<opponentPokemon.getName() <<"! -----" << endl;
}

void Battle::chooseInitialActivePokemon() {
    changeTheActivePokemon();
    if (!isBattleOver()) {
        cout << "Vous appelez " << player.getActivePokemon().getName() << endl;
    }
}

int Battle::getPlayerAction() {
    int userInputAboutAction;
    cout << "Que voulez vous faire?" << endl;
    cout << "   [1] : attaquer" << endl;
    cout << "   [2] : utiliser une pokeball" << endl;
    cout << "   [3] : utiliser une potion de soin" << endl;
    cout << "   [4] : changer de pokemon" << endl;
    cout << "   [5] : s'enfuir." << endl;
    while (true) {
        cout << "Choisissez votre action :" << endl;
        cin >> userInputAboutAction;
        if (cin.fail() || userInputAboutAction < 1 || userInputAboutAction > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return userInputAboutAction;
        }
    }
}

void Battle::changeTheActivePokemon() {
    player.getTeam().displayInfoTeam();
    if (player.getTeam().areAllPokemonInTeamDead()) {
        cout << "Vous n'avez plus de pokemon disponible, vous avez perdu le combat :(" << endl;
        battleOutcome = BattleOutcome::PLAYER_LOST;
    }
    else {
        int userInputPositionPokemonToSetActive = selectIndexOfPokemonToSetActive();
        player.changeActivePokemonByPokemonAtIndex(userInputPositionPokemonToSetActive);
    }
}


int Battle::selectIndexOfPokemonToSetActive() {
    int userInputPositionPokemonToSetActive;
    cout << "Quel pokemon voulez vous appeler?" << endl;
    while (true) {
        cin >> userInputPositionPokemonToSetActive;
        if (cin.fail() || userInputPositionPokemonToSetActive < 1 || userInputPositionPokemonToSetActive > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return userInputPositionPokemonToSetActive - 1;
        }
    }
}

void Battle::doActionInBattle(int actionToDoIndex) {
    switch (actionToDoIndex) {
        case 1:
            player.getActivePokemon().attackPokemon(opponentPokemon);
            if (opponentPokemon.isPokemonDead()) {
                battleOutcome = BattleOutcome::PLAYER_WON;
                cout << "Vous avez gagné !" << endl;
            }
            break;
        case 2:
            player.useOnePokeballOn(opponentPokemon);
            if (player.isThePokeballEfficient(opponentPokemon)) {
                battleOutcome = BattleOutcome::OPPONENT_CAPTURED;  // voir bug n°4 ci-dessous
            }
            break;
        case 3:
            player.useHealPotion();
            break;
        case 4:
            changeTheActivePokemon();
            break;
        case 5:
            battleOutcome = BattleOutcome::PLAYER_LOST;
            cout << "Vous vous etes enfuit ! " << endl;

            break;
        default:
            std::cerr << "Action non valide" << std::endl;
    }
}

bool Battle::isBattleOver() const {
    return (battleOutcome != BattleOutcome::NOT_ENDED);
}

bool Battle::isTheBattleGoingToEnd() const {
    bool canOpponentPokemonWin = player.getActivePokemon().getDefense() < opponentPokemon.getAttack();
    bool canPlayerPokemonWin = opponentPokemon.getDefense() < player.getActivePokemon().getAttack();
    return canOpponentPokemonWin || canPlayerPokemonWin;
}

BattleOutcome Battle::runBattle() {
    if (!isTheBattleGoingToEnd()) {
        battleOutcome = BattleOutcome::PLAYER_WON;
        cout << "Le combat pouvait ne jamais finir, vous avez gagne par defaut! " << endl;
    }
    while (!isBattleOver()) {
        doActionInBattle(getPlayerAction());
        if (isBattleOver()) {
            break;
        }
        opponentPokemon.attackPokemon(player.getActivePokemon());
        if (player.getActivePokemon().isPokemonDead()) {
            changeTheActivePokemon();
        }

    }
    return battleOutcome;
}
