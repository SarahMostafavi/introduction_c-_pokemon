//
// Created by 33651 on 03/10/2026.
//

#ifndef TICTACTOE_INFOCONSOLEROOM_H
#define TICTACTOE_INFOCONSOLEROOM_H
#include <string>
#include <vector>
#include <iostream>
#include "../../inc/GameEngine.h"


/**
 *  The class display in the console information about the states of the game.
 */
class InfoConsoleRoom {
    public :
    /**
     * Display the options of starter pokemons from generation generationIndex
     * among starterOption to choose.
     * @param generationIndex
     * @param starterOptions
     */
    static void displayStarterOptions(int generationIndex, const std::vector<std::string>& starterOptions);

    static void displayInvalidEntryMessage();

    /**
     * Display the error message if the pokemon star selected is not valid.
     */
    static void displayStarterErrorMessage();

    /**
     * Display the message when a pokemon starter is selected.
     * @param name
     */
    static void displayStarterChosenMessage(const std::string &name);

    /**
     * Display the welcome message of the CenterRoom
     */
    static void displayCenterRoomWelcomeMessage();

    /**
     * Display that the entry is invalid and the welcome message of the CenterRoom.
     */
    static void displayCenterRoomErrorMessage();

    /**
     * Display that the player gets additionals pokeballs.
     * @param engine
     */
    static void displayGetAdditionalPokeballsMessage(GameEngine& engine);

    /**
     * Display that the player gets additional hel potions.
     * @param engine
     */
    static void displayGetAdditionalHealPotionsMessage(GameEngine&engine);

    /**
     * Display the message asking if the player wants to modify the team.
     * @param engine
     */
    static void displayModifyTeamPlayerMessage(GameEngine& engine);

    /**
     * Display the message asking what pokemon the player wants to add to the team.
     * @param engine
     */
    static void displayPlayerPartyMessage(GameEngine& engine);

    /**
     * Display the message asking the player what is the position he wants to add the pokemon.
     * @param engine
     */
    static void displayAddingInTeamMessage(GameEngine& engine);

    /**
     * Display the message saying the party is empty so it is not possible to modify the team.
     */
    static void displayPartyEmptyMessage();

};


#endif //TICTACTOE_INFOCONSOLEROOM_H
