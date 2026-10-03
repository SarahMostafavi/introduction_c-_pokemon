//
// Created by 33651 on 01/10/2026.
//

#include "../inc/GameEngine.h"

#include <iostream>

#include "../inc/room/MenuRoom.h"
#include "../inc/room/StartersRoom.h"

Room * GameEngine::decideNextRoom(RoomEvent event) {
    switch (event) {
        case RoomEvent::PlayGame:
            return new StartersRoom();
        case RoomEvent::QuitGame:
            std::cout<<"~~~ End of game ~~~"<<std::endl;
            return nullptr;
        case RoomEvent::StartersChosen:
            std::cout<<"~~~ Starters are selected of game ~~~"<<std::endl;
            return nullptr;
        default:
            return nullptr;
    }
}

GameEngine::GameEngine(): currentRoom(new MenuRoom()) {
}

Player& GameEngine::getPlayer() {
    return player;
}


void GameEngine::run() {
    while (currentRoom != nullptr) {
        RoomEvent event = currentRoom->runRoom(*this);
        Room* next = decideNextRoom(event);
        delete currentRoom;
        currentRoom = next;
    }
}

