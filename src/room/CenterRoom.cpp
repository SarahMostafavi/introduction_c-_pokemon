//
// Created by 33651 on 03/10/2026.
//

#include "../../inc/room/CenterRoom.h"

#include <limits>

#include "../../inc/GameEngine.h"
#include "../../inc/room/InfoConsoleRoom.h"
using namespace std;

CenterRoom::CenterRoom() {
    cout << "~~~ CenterRoom Constructor ~~~"<<endl;
}

void CenterRoom::modifyPlayerTeam(GameEngine &engine) const {
    while (true) {
        string userInputAboutModifyingPlayerTeam;
        InfoConsoleRoom::displayModifyTeamPlayerMessage(engine);
        cin >> userInputAboutModifyingPlayerTeam;

        if (userInputAboutModifyingPlayerTeam == "n") {
            break;
        }
        if (userInputAboutModifyingPlayerTeam == "y") {
            if (!engine.getPlayer().getParty().isPokemonPartyEmpty()) {
                addPokemonInTheTeam(engine);
            }else {
                InfoConsoleRoom::displayPartyEmptyMessage();
                break;
            }
        }
    }
}

Pokemon CenterRoom::selectPokemonToAdd(GameEngine &engine) {
    int userInputAboutPokemonIndexToAdd;
    InfoConsoleRoom::displayPlayerPartyMessage(engine);
    while (true) {
        cin >> userInputAboutPokemonIndexToAdd;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            string userInputAboutModifyingPlayerTeam;
            InfoConsoleRoom::displayModifyTeamPlayerMessage(engine);
            continue;
        }
        try {
            return engine.getPlayer().getParty().getPokemonByIndex(userInputAboutPokemonIndexToAdd - 1);
        }
        catch (std::invalid_argument& e) {
            InfoConsoleRoom::displayInvalidEntryMessage();
        }
    }

}

int CenterRoom::selectThePositionToAdd(GameEngine &engine) {
    int userInputAboutPositionToAdd;
    InfoConsoleRoom::displayAddingInTeamMessage(engine);
    while (true) {
        cin >> userInputAboutPositionToAdd;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            InfoConsoleRoom::displayInvalidEntryMessage();
            continue;
        }
        break;
    }
    return userInputAboutPositionToAdd - 1;
}

void CenterRoom::addPokemonInTheTeam(GameEngine &engine) {
    Pokemon pokemonToAddInTheParty = selectPokemonToAdd(engine);
    int positionToAddInTheParty = selectThePositionToAdd(engine);
    try {
        engine.getPlayer().getTeam().putPokemonFromPokemonPartyInPosition(pokemonToAddInTheParty, engine.getPlayer().getParty(), positionToAddInTheParty);
    }
    catch (std::out_of_range& e) {
            InfoConsoleRoom::displayInvalidEntryMessage();
    }

}


void CenterRoom::getAdditionalPokeballs(GameEngine& engine) const {
    engine.getPlayer().addAdditionalPokeballs(NUMBER_OF_POKEBALLS_GET);
    InfoConsoleRoom::displayGetAdditionalPokeballsMessage(engine);
}

void CenterRoom::getAdditionalHealPotions(GameEngine& engine) const {
    engine.getPlayer().addAdditionalHealPotion(NUMBER_OF_HEAL_POTIONS_GET);
    InfoConsoleRoom::displayGetAdditionalHealPotionsMessage(engine);
}

RoomEvent CenterRoom::doActionInCenterRoom(GameEngine& engine, int indexActionToDo) const {
    switch (indexActionToDo) {
        case 1:
            modifyPlayerTeam(engine);
            return RoomEvent::ENTER_CENTER;
        case 2:
            getAdditionalPokeballs(engine);
            return RoomEvent::ENTER_CENTER;
        case 3:
            getAdditionalHealPotions(engine);
            return RoomEvent::ENTER_CENTER;
        case 4:
            return RoomEvent::START_EXPLORATION;
        case 5:
            return RoomEvent::START_ARENA;
        default:
            return RoomEvent::ENTER_CENTER;
    }
    return  RoomEvent::ENTER_CENTER;
}

RoomEvent CenterRoom::runRoom(GameEngine &engine) {
    int userInput;
    InfoConsoleRoom::displayCenterRoomWelcomeMessage();
    while (true) {
        cin >> userInput;
        if (cin.fail() || userInput<1 || userInput>5) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            InfoConsoleRoom::displayCenterRoomWelcomeMessage();
        }
        else {
            break;
        }
    }
    return doActionInCenterRoom(engine, userInput);
}




