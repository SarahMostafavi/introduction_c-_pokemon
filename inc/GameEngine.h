//
// Created by 33651 on 01/10/2026.
//

#ifndef TICTACTOE_GAMEENGINE_H
#define TICTACTOE_GAMEENGINE_H

#include "Player.h"
#include "room/Room.h"

/**
 * Class that allows to change of rooms during the game.
 */
class GameEngine {
    private:
    Room *currentRoom;
    Player player;

    /**
     * Depending of the event decide the new room.
     * @param event
     * @return
     */
    static Room* decideNextRoom(RoomEvent event);

    public:
    GameEngine();
    Player& getPlayer();

    /**
     * Run the main game loop, which changes rooms as the game progresses
     */
    void run();
};


#endif //TICTACTOE_GAMEENGINE_H
