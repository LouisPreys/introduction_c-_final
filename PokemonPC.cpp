//
// Created by louis on 11/09/2024.
//

#include "PokemonPC.h"
#include "Pokedex.h"
#include "SetOfPokemon.h"
#include <iostream>
#include <cstdlib> // pour rand et srand

void PokemonPC::EncounterPokemon(std::vector<Pokemon*>& capturedPokemon){
    int value = rand()%721;
    Pokemon* encounter = Pokedex::getInstance()->getOnePokemonById(value);
    if (encounter != nullptr) {
    std::cout << "Vous trouvez " << encounter->getName() << " !" << std::endl;
        if (rand()%100 >= 20) {
            capturedPokemon.push_back(encounter);
            std::cout << "Vous avez capture " << encounter->getName() << " !" << std::endl;
            encounter->displayInfo();
        }
        else {
            std::cout << encounter -> getName() << " s'est enfui" << std::endl;
        }
    }
    else {
        std::cout << "Vous ne trouvez rien" << std::endl;
    }
}

void PokemonPC::addPokemon(Pokemon* pokemon, std::vector<Pokemon*>& capturedPokemon) {
    capturedPokemon.push_back(pokemon);
}

const std::vector<Pokemon*> PokemonPC::getCapturedPokemon(std::vector<Pokemon*>& capturedPokemon) {
    return capturedPokemon;
}

Pokemon* PokemonPC::getOnePokemonByName(string name) {
    int IndexInList = this -> FindByName(name);
    if (IndexInList!=-1) {
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokemon* PokemonPC::getOnePokemonById(int id) {
    int IndexInList = this -> FindById(id);
    if (IndexInList!=-1){
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

PokemonPC::PokemonPC() {

}



