//
// Created by 33651 on 03/10/2026.
//

#ifndef TICTACTOE_CENTERROOM_H
#define TICTACTOE_CENTERROOM_H
#include "Room.h"
#include "../pokemon/Pokemon.h"
class GameEngine;

/**
 * Class representing the room where player can change his team, get additional pokeball, get additional heal potions,
 * starts exploration mode, start arena mode.
 */
class CenterRoom : public Room{
    private:
    const int NUMBER_OF_HEAL_POTIONS_GET = 3;
    const int NUMBER_OF_POKEBALLS_GET = 1;

    /**
    * Ask the player if he wants to modify the Team and modify it.
    * @param engine
    */
    void modifyPlayerTeam(GameEngine& engine) const;

    /**
     * Ask the player which pokemon he wants to add in the team
     * @param engine
     * @return the pokemon to add
     */
    static Pokemon selectPokemonToAdd(GameEngine& engine);

    /**
     * Ask the player at which positon he wants to add the pokemon.
     * @param engine
     * @return
     */
    static int selectThePositionToAdd(GameEngine &engine) ;

    /**
     * Add in the team at the chosen position the pokemon from the party chosen by the player.
     * @param engine
     */
    static void addPokemonInTheTeam(GameEngine &engine);

    /**
     * The player gets Additional pokeball
     * @param engine
     */
    void getAdditionalPokeballs(GameEngine& engine) const;

    /**
     * The player gets additional heal potions.
     * @param engine
     */
    void getAdditionalHealPotions(GameEngine& engine) const ;

    /**
     * Give the event associated to the action chosen by the player.
     * @param engine
     * @param indexActionToDo
     * @return the event the player choosed to do
     */
    RoomEvent doActionInCenterRoom(GameEngine& engine, int indexActionToDo) const ;

    public:
    CenterRoom();

    /**
     * Ask the player what action wants to do in the pokemon center and do the action.
     * @param engine
     * @return
     */
    RoomEvent runRoom(GameEngine &engine) override;
};

#endif //TICTACTOE_CENTERROOM_H
