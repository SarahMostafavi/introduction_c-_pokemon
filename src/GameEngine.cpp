//
// Created by 33651 on 01/10/2026.
//

#include "../inc/GameEngine.h"

#include <iostream>
#include "../inc/room/MenuRoom.h"
#include "../inc/room/StartersRoom.h"
#include "../inc/room/CenterRoom.h"
#include "../inc/room/ExplorationRoom.h"

Room * GameEngine::decideNextRoom(RoomEvent event) {
    switch (event) {
        case RoomEvent::PLAY_GAME:
            return new StartersRoom();
        case RoomEvent::QUIT_GAME:
            std::cout<<"~~~ End of game ~~~"<<std::endl;
            return nullptr;
        case RoomEvent::ENTER_CENTER:
            std::cout<<"~~~ Starters are selected of game ~~~"<<std::endl;
            return new CenterRoom();
        case RoomEvent::START_EXPLORATION:
            std::cout<<"~~~ Starts Exploration ~~~"<<std::endl;
            return new ExplorationRoom();
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

