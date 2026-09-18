#include <iostream>
#include "../inc/Pokemon.h"
#include "../inc/InfoConsole.h"
#include "../inc/Pokedex.h"

int main() {
    Pokedex* pokedex = Pokedex::getInstance("../data/pokedex.csv");
    Pokemon* playerPokemon = nullptr;
    Pokemon* opponentPokemon = nullptr;

    //Choix du pokemon du joueur
    while (playerPokemon == nullptr) {
        std::cout << "Bonjour, choisissez votre pokemon (nom)" << std::endl;
        string playerPokemonName;
        std::cin >> playerPokemonName;
        try{
            playerPokemon = new Pokemon(pokedex->getPokemonByName(playerPokemonName));
        }
        catch (std::exception& e) {
            std::cerr << "Le nom " << playerPokemonName << " n'est pas valide." << std::endl;
        }
    }

    std::cout << "Voici les info sur votre pokemon :" << std::endl;
    InfoConsole::displayInfo(*playerPokemon);
    //Fin du choix du pokemon du joueur


    // Choix du pokemon de l'adversaire
    while (opponentPokemon == nullptr) {
        std::cout << "Choisissez le pokemon de votre adversaire(nom)" << std::endl;
        string opponentPokemonName;
        std::cin >> opponentPokemonName;

        try{
            opponentPokemon = new Pokemon(pokedex->getPokemonByName(opponentPokemonName));
        }
        catch (std::exception& e) {
            std::cerr << "Le nom " << opponentPokemonName << " n'est pas valide." << std::endl;
        }

    }
    std::cout << "Voici les info sur le pokemon de votre adversaire:" << std::endl;

    InfoConsole::displayInfo(*opponentPokemon);
    // Fin du choix du pokemon de l'adversaire


    // Combat entre les pokemon tant qu'aucun des des n'est mort
    std::cout <<"Debut du combat entre " << playerPokemon->getName() << " et " << opponentPokemon->getName() << std::endl;

    while (playerPokemon->getHitPoint() > 0 && opponentPokemon->getHitPoint() > 0) {
        playerPokemon->attackPokemon(*opponentPokemon);

        if (opponentPokemon->getHitPoint() <= 0) {
            break; // Le combat s'arrete si un pokemon meurt
        }

        opponentPokemon->attackPokemon(*playerPokemon);
        opponentPokemon->healOf(-5);
    }
    // Fin du combat

    return 0;
}
