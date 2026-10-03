//
// Created by 33651 on 01/10/2026.
//

#include "../../inc/room/MenuRoom.h"

#include <iostream>
#include <string>
using std::string;

MenuRoom::MenuRoom()
{
    std::cout << "~~~ MenuRoom constructor ~~~" << std::endl;
}

RoomEvent MenuRoom::runRoom(GameEngine &engine) {
    std::cout << "Bonjour!" << std::endl;
    string userInput;
    while (true) {
        std::cout << "Pour commencer à jouer au jeu Pokemon entrez 'j'."<<std::endl;
        std::cout << "Pour quitter le jeu entrez 'q' " << std::endl;
        std::cin >> userInput;
        if (userInput == "j") {
            return RoomEvent::PlayGame;
        }
        if (userInput == "q") {
            return RoomEvent::QuitGame;
        }
        else {
            std::cerr << "L'entree '" << userInput << "' n'est pas valide!" << std::endl;
        }
    }

}