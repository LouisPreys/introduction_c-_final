//
// Created by louis on 09/09/2024.
//

#include "Pokedex.h"
#include <fstream>
#include <sstream>
#include <iostream>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(string fileName):SetOfPokemon() {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "File" << fileName << " not found " << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> dataline;

        while (std::getline(ss, cell, ',')) {
            dataline.push_back(cell);
        }

        int id = std::stoi(dataline.at(0));
        double hitPoint = std::stod(dataline.at(5));
        double attack = std::stod(dataline.at(6));
        double defense = std::stod(dataline.at(7));
        double spattack = std::stod(dataline.at(8));
        double spdefense = std::stod(dataline.at(9));
        double speed = std::stoi(dataline.at(10));
        int generation = std::stoi(dataline.at(11));

        arrayOfPokemon.push_back(new Pokemon(id, dataline.at(1), hitPoint, attack, defense,
                                             spattack, spdefense, speed, generation));
    }
}

Pokemon* Pokedex::getOnePokemonByName(string name) {
    int IndexInList = this -> FindByName(name);
    if (IndexInList!=-1){
        return new Pokemon(*(this -> arrayOfPokemon.at(IndexInList))); //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokemon* Pokedex::getOnePokemonById(int id) {
    int IndexInList = this -> FindById(id);
    if (IndexInList!=-1){
        return new Pokemon(*(this -> arrayOfPokemon.at(IndexInList))); //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokedex::~Pokedex(){

}

Pokedex* Pokedex::getInstance(){
    if (instance == nullptr){
        instance = new Pokedex("../ressources/pokedex.csv");
    }
    return instance;
}
