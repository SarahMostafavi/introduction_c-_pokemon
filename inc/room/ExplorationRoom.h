//
// Created by 33651 on 04/10/2026.
//

#ifndef TICTACTOE_EXPLORATIONROOM_H
#define TICTACTOE_EXPLORATIONROOM_H
#include "Room.h"


/**
 *
 */
class ExplorationRoom : public Room {

public:
    ExplorationRoom();

    static bool askUserToContinueExploring();

    RoomEvent runRoom(GameEngine &engine) override;
};


#endif //TICTACTOE_EXPLORATIONROOM_H
