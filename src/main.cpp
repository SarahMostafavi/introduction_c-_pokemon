#include <iostream>
#include "../inc/Pokemon.h"
#include "../inc/InfoConsole.h"
#include "../inc/Pokedex.h"
#include "../inc/PokemonParty.h"
#include "../inc/PokemonTeam.h"

int main() {
    auto pokedex = Pokedex::getInstance("data/pokedex.csv");
    auto* pokemonParty = new PokemonParty();
    auto* pokemonTeam = new PokemonTeam();

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

    pokemonParty->addPokemon(*playerPokemon);
    pokemonTeam->putPokemonFromPokemonPartyInPosition(*playerPokemon, *pokemonParty,0);

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
    bool isTheFightGoingToEnd = ((playerPokemon->getDefense() < opponentPokemon->getAttack()) || (opponentPokemon->getDefense() < playerPokemon->getAttack()));
    if (isTheFightGoingToEnd) {
        while (playerPokemon->getHitPoint() > 0 && opponentPokemon->getHitPoint() > 0) {
            playerPokemon->attackPokemon(*opponentPokemon);

            if (opponentPokemon->getHitPoint() <= 0) {
                break; // Le combat s'arrete si un pokemon meurt
            }

            opponentPokemon->attackPokemon(*playerPokemon);
        }
    }

    else{
        std::cout << "Ce combat n'a pas de fin, il y a egalite." << std::endl;
    }

    if (opponentPokemon->getHitPoint() == 0) {
        pokemonParty->addPokemon(*opponentPokemon);
        pokemonTeam->putPokemonFromPokemonPartyInPosition(*opponentPokemon, *pokemonParty,0);
    }

    pokemonTeam->displayInfoTeam();
    
    // Fin du combat
    delete playerPokemon;
    delete opponentPokemon;
    delete pokemonParty;
    delete pokemonTeam;

    return 0;
}
