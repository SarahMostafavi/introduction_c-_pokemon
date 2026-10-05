//
// Created by 33651 on 04/10/2026.
//

#ifndef TICTACTOE_BATTLE_H
#define TICTACTOE_BATTLE_H

#include "../inc/pokemon/Pokemon.h"
#include "../inc/Player.h"


enum class BattleOutcome { NOT_ENDED, PLAYER_WON, PLAYER_LOST, OPPONENT_CAPTURED };

class Battle {
private:
    Player& player;
    Pokemon &opponentPokemon;
    BattleOutcome battleOutcome;

    /**
     * Get the index of the action the player wants to do.
     * @return
     */
    static int getPlayerAction();

    /**
     * Change the active pokemon by the one chosen by the player. A pokemon dead can't be selected.
     */
    void changeTheActivePokemon();

    /**
     * Ask the player what is the position of the pokemon that the player wants set active.
     * @return
     */
    int selectIndexOfPokemonToSetActive();

    /**
     * Do the action slected by the user.
     * @param actionToDoIndex
     */
    void doActionInBattle(int actionToDoIndex);

    /**
     * Says if the battle is over.
     * @return
     */
    bool isBattleOver() const;

    bool isTheBattleGoingToEnd() const;

public:
    Battle(Player &player, Pokemon &opponent);

    /**
     * Ask the player to choose their first active pokemon before the battle starts.
     */
    void chooseInitialActivePokemon();

    /**
     * Run the battle until one of the
     * @return
     */
    BattleOutcome runBattle();
};


#endif //TICTACTOE_BATTLE_H
