#include <iostream>
#include "../inc/Pokemon.h"
#include "../inc/InfoConsole.h"
#include "../inc/Pokedex.h"

int main() {
    // // Test des constucteurs et destructeurs
    // Pokemon bulbizarre = Pokemon(1,"Bulbizarre", 0,40,  30, 20, 10, 1);
    // InfoConsole::displayInfo(bulbizarre);
    //
    // Pokemon bulbizarre2 = Pokemon(bulbizarre);
    // InfoConsole::displayInfo(bulbizarre2);
    // // Fin test des constructeurs et destructeurs
    //
    // // Test des attaques
    // std::cout<<"Test attaque pokemon" <<std::endl;
    // std::cout <<"Nombre de pokemons instancies : " << Pokemon::getNumberOfPokemons() << std::endl;
    // Pokemon pokemonA(2,"A", 0,50,50, 20,10 ,1);
    // Pokemon pokemonB(3,"B", 0,30,30, 40,30 ,1);
    // pokemonA.attackPokemon(pokemonB);
    // pokemonB.attackPokemon(pokemonA);
    // pokemonB.attackPokemon(pokemonA);
    // std::cout <<"Nombre de pokemons instancies : " << Pokemon::getNumberOfPokemons() << std::endl;



    Pokedex* pinstance = Pokedex::getInstance("../data/pokedex.csv");
    Pokemon pokemon1 = pinstance->getPokemonById(0);
    InfoConsole::displayInfo(pokemon1);
    Pokemon pokemon2 = pinstance->getPokemonById(1);
    InfoConsole::displayInfo(pokemon2);
    Pokemon pokemon3 = pinstance->getPokemonByName("Bulbasaur");
    InfoConsole::displayInfo(pokemon3);
    Pokemon pokemon4 = pinstance->getPokemonByName("Ivysaur");
    InfoConsole::displayInfo(pokemon4);

    return 0;
}
