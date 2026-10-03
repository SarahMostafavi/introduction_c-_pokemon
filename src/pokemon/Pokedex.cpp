//
// Created by 33651 on 14/09/2026.
//

#include "../../inc/pokemon/Pokedex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Pokedex* Pokedex::pinstance = nullptr;

Pokedex::Pokedex(string fileName):SetOfPokemon() {

    std::cout << "~~~ Constructeur du Pokedex ~~~" << std::endl;

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

        arrayOfPokemon.push_back(new Pokemon(id,lineData.at(1),
            hitPoint, hitPoint,attackValue, defenseValue));
    }
}

Pokedex *Pokedex::getInstance(const string& fileName) {
    if (pinstance == nullptr) {
        pinstance = new Pokedex(fileName);
    }
    return pinstance;
}

// Ajouter exception si id invalide
Pokemon Pokedex::getPokemonById(int id){
    return Pokemon(*arrayOfPokemon.at(id));
}



Pokemon Pokedex::getPokemonByName(string name) {
    for (Pokemon* pokemon : arrayOfPokemon) {
        if (name == pokemon->getName()) {
            return Pokemon(*pokemon);
        }
    }
    // Exception si le pokémon n'existe pas.
    throw std::invalid_argument("Le pokemon" + name + " n'exite pas, verifiez l'orthographe.");
}







