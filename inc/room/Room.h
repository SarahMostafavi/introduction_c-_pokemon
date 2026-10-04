//
// Created by 33651 on 01/10/2026.
//

#ifndef TICTACTOE_ROOM_H
#define TICTACTOE_ROOM_H

enum class RoomEvent { PLAY_GAME, QUIT_GAME, ENTER_CENTER, START_EXPLORATION, START_ARENA };

class GameEngine;

/**
 * Abstract class describing the actions of a Room.
 */
class Room {
public:
    virtual ~Room() = default;

    /**
     * Action of the room.
     * @param engine
     * @return
     */
    virtual RoomEvent runRoom(GameEngine &engine)=0;
};


#endif //TICTACTOE_ROOM_H
