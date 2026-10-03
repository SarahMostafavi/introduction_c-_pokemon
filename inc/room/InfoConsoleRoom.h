//
// Created by 33651 on 03/10/2026.
//

#ifndef TICTACTOE_INFOCONSOLEROOM_H
#define TICTACTOE_INFOCONSOLEROOM_H
#include <string>
#include <vector>
#include <iostream>

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

    /**
     * Display the error message if the pokemon star selected is not valid.
     */
    static void displayStarterErrorMessage();

    /**
     * Display the message when a pokemon starter is selected.
     * @param name
     */
    static void displayStarterChosenMessage(const std::string &name);
};


#endif //TICTACTOE_INFOCONSOLEROOM_H
