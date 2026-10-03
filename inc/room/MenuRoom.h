//
// Created by 33651 on 01/10/2026.
//

#ifndef TICTACTOE_MENUROOM_H
#define TICTACTOE_MENUROOM_H
#include "Room.h"

/**
 * Class representing the state of the menu.
 * 2 actions are possible play or quit.
 */
class MenuRoom : public Room{
    public:
    MenuRoom();

    /**
     * Display Menu, allows to play or quit.
     * @param engine
     * @return
     */
    RoomEvent runRoom(GameEngine &engine) override;
};


#endif //TICTACTOE_MENUROOM_H
