//
// Created by 33651 on 14/09/2026.
//

#ifndef TICTACTOE_POKEMON_H
#define TICTACTOE_POKEMON_H

#include <string>
using std::string;
class InfoConsole;

/**
 * Represents a Pokemon.
 * The Pokemon can attack and inflicts damages on another pokemon.
 * The class count the number of pokemon instantiated.
 **/
class Pokemon {
private:
    int id;
    const string name;
    int evolution;
    double hitPointMax;
    double hitPoint;
    double attack;
    double defense;
    int generation;
    static int numberOfPokemons;


public:
    Pokemon() = delete;
    Pokemon(int id, const string &name, int evolution, double hitPointMax, double hitPoint, double attack, double defense, int generation);
    Pokemon(const Pokemon& anotherPokemon);
    ~Pokemon();

    int getId() const;
    string getName() const;
    int getEvolution() const;
    double getHitPointMax() const;
    double getHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    int getGeneration() const;

    static int getNumberOfPokemons();

    /**
     * The pokemon attack another pokemon.
     * The attack is successful if the attack value is greater than the defense of the other pokemon.
     *
     * @param anotherPokemon
     **/
    void attackPokemon(Pokemon &anotherPokemon) const;


    /**
     * The pokemon inflicts damage on another pokemon.
     * The attacked pokemon die if his hit points are less than zero.
     *
     * @param anotherPokemon
     * @return true if the attack is fatal
     **/
    bool inflictDamageOn(Pokemon& anotherPokemon) const;

    /**
     * The pokemon is healed of amountTOHeal if the amount to heal is positive.
     * The hitPoints of the pokemon can't be superior at the hitPointsMax.
     * @param amountToHeal
     */
    void healOf(double amountToHeal);
};


#endif //TICTACTOE_POKEMON_H
