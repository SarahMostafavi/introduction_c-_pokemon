//
// Created by 33651 on 14/09/2026.
//

#ifndef TICTACTOE_INFOCONSOLE_H
#define TICTACTOE_INFOCONSOLE_H


#include <string>
#include "Pokemon.h"
using std::string;

/**
 *  The class display in the console information about pokemon's attacks.
 */
class InfoConsole {
public:

    /**
     * Display the information known about the pokemon
     * @param pokemon
     */
    static void displayInfo(const Pokemon &pokemon);


    /**
     * Display that the pokemon is attacking another one
     * and tells if the attack is successful or not.
     *
     * @param isAttackSuccessful
     * @param attacker
     * @param defender
     */
    static void displayAttackSuccessInfo(
        const bool &isAttackSuccessful, const Pokemon &attacker, const Pokemon &defender);


    /**
     * @brief Display the damage the pokemon inflicted to another pokemon
     * and if the pokemon attacked is dead or not.
     *
     * @param isAttackFatal
     * @param attacker
     * @param defender
     * @param damageInflicted
     */
    static void displaySuccessfulAttackInfo(
        const bool &isAttackFatal, const Pokemon &attacker, const Pokemon &defender, const double &damageInflicted);
};


#endif //TICTACTOE_INFOCONSOLE_H
