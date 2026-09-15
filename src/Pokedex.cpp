//
// Created by 33651 on 14/09/2026.
//

#include "../inc/Pokedex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Pokedex* Pokedex::pinstance = nullptr;
vector<string> Pokedex::arrayOfPokemonNames;

Pokedex::Pokedex(std::pmr::string fileName):SetOfPokemon() {

    std::cout << "*** Constructeur du Pokedex ***" << std::endl;

    std::ifstream file((fileName.data()));
    if(!file.is_open()){
        std::cerr<<"File "<<fileName<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }
        int id = std::stoi(lineData.at(0));
        double attackValue = std::stod(lineData.at(6));
        double hitPoint = std::stod(lineData.at(5));
        double defenseValue = std::stod(lineData.at(7));
        int generation = std::stoi(lineData.at(11));

        arrayOfPokemon.push_back(new Pokemon(id,lineData.at(1),0,
            hitPoint, hitPoint,attackValue, defenseValue,generation));
    }
}

Pokedex *Pokedex::getInstance(const std::pmr::string& fileName) {
    if (pinstance == nullptr) {
        pinstance = new Pokedex(fileName);
        for (Pokemon* pokemon : pinstance->arrayOfPokemon) {
            arrayOfPokemonNames.push_back(pokemon->getName());
        }
    }
    return pinstance;
}

// Ajouter exception si id invalide
Pokemon Pokedex::getPokemonById(int id){
    return Pokemon(*arrayOfPokemon.at(id));
}



Pokemon Pokedex::getPokemonByName(string name) {
    for (int id=0; id<arrayOfPokemonNames.size(); id++) {
        if (name == arrayOfPokemonNames.at(id)) {
            return Pokemon(*arrayOfPokemon.at(id));
        }
    }
    // Exception si le pokémon n'existe pas.
    throw std::invalid_argument("Pokemon name" + name + " not found");
}







