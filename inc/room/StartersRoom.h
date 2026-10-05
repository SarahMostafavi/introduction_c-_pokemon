//
// Created by 33651 on 01/10/2026.
//

#ifndef TICTACTOE_STARTERSROOM_H
#define TICTACTOE_STARTERSROOM_H

#include "Room.h"
#include "../pokemon/Pokedex.h"
#include <vector>
#include <string>

/**
 * Class representing the state where we choose 4 starters of pokemon.
 * The options of starters are the starters of the 3 first generations and 3 starters more powerful
 */
class StartersRoom : public Room {
private:
    std::vector<string> nameOfStartersSelected;

    const std::vector<vector<string>> startersGenArray = {
        {"Bulbasaur", "Charmander", "Squirtle"},
        {"Chikorita", "Cyndaquil", "Totodile"},
        {"Treecko", "Torchic", "Mudkip"},
        {"Sandshrew", "Teddiursa", "Carvanha" }

    };
    /**
     * Give the options of starters given the generation of pokemon.
     * The user needs to give in input the index of the starter selected.
     * The starter index needs to be an int between 1 and 3.
     * @param generationIndex
     * @return
     */
    int askUserToChooseStarter(int generationIndex) const;

    /**
     * Add the starter to the pokemon party of the player.
     * @param engine
     * @param pokedex
     * @param name
     */
    static void addStarterToParty(GameEngine& engine, Pokedex* pokedex, const std::string& name);

public:
    StartersRoom();

    /**
     * Allows the player to choose 3 starters and add them to the pokemon party of the player.
     * @param engine
     * @return
     */
    RoomEvent runRoom(GameEngine& engine) override;

};
#endif //TICTACTOE_STARTERSROOM_H
