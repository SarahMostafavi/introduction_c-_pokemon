//
// Created by 33651 on 01/10/2026.
//

#include "../../inc/room/StartersRoom.h"

#include <iostream>
#include <limits>

#include "../../inc/GameEngine.h"
#include "../../inc/room/InfoConsoleRoom.h"
using namespace std;


StartersRoom::StartersRoom(){
    std::cout<<"~~~ StartersRoom constructor ~~~"<< std::endl;
    nameOfStartersSelected.resize(3);

}

RoomEvent StartersRoom::runRoom(GameEngine &engine) {
    Pokedex* pokedex = Pokedex::getInstance("data/pokedex.csv");
    for (int i = 0; i < startersGenArray.size(); i++) {
        int indexPokemonSelected = askUserToChooseStarter(i);
        nameOfStartersSelected.at(i) = startersGenArray.at(i).at(indexPokemonSelected);
        addStarterToParty(engine, pokedex, nameOfStartersSelected.at(i));
    }
    return RoomEvent::ENTER_CENTER;
}

int StartersRoom::askUserToChooseStarter(int generationIndex) const {
    int userInput;
    InfoConsoleRoom::displayStarterOptions(generationIndex, startersGenArray.at(generationIndex));
    while (true) {
        cin >> userInput;
        if (cin.fail() || userInput<1 || userInput>3) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            InfoConsoleRoom::displayStarterErrorMessage();
        }
        else {
            break;
        }
    }
    return userInput-1;
}

void StartersRoom::addStarterToParty(GameEngine& engine, Pokedex* pokedex, const string& name) {
    Pokemon pokemonSelected = pokedex->getPokemonByName(name);
    InfoConsoleRoom::displayStarterChosenMessage(name);
    engine.getPlayer().getParty().addPokemon(pokemonSelected);
}
