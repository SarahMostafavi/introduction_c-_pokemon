//
// Created by 33651 on 04/10/2026.
//

#include "../../inc/room/ExplorationRoom.h"
#include "../../inc/Battle.h"

#include <iostream>
#include <ostream>

#include "../../inc/GameEngine.h"
#include "../../inc/pokemon/Pokedex.h"

ExplorationRoom::ExplorationRoom() {
    std::cout << "~~~ ExplorationRoom Constructor ~~~"<<std::endl;
}

bool ExplorationRoom::askUserToContinueExploring() {
    std::string userInput;
    std::cout << "Voulez-vous continuer à explorer ? (y/n)" << std::endl;
    while (true) {
        std::cin >> userInput;
        if (userInput == "y") {
            return true;
        }
        if (userInput == "n") {
            return false;
        }
        std::cerr << "Entrée invalide." << std::endl;
    }
}


RoomEvent ExplorationRoom::runRoom(GameEngine &engine) {

    while (true) {
        std::cout << "Un pokemon surgit !" << std::endl;
        Pokedex* pokedex = Pokedex::getInstance("data/pokedex.csv");
        Pokemon opponent = pokedex->getRandomPokemon();

        Battle battle(engine.getPlayer(), opponent);
        battle.chooseInitialActivePokemon();

        BattleOutcome outcome = battle.runBattle();
        if (outcome == BattleOutcome::PLAYER_LOST) {
            return RoomEvent::ENTER_CENTER;
        }

        if (!askUserToContinueExploring()) {
            return RoomEvent::ENTER_CENTER;
        }
    }
}
