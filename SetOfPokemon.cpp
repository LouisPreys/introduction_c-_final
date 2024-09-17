//
// Created by louis on 09/09/2024.
//

#include "SetOfPokemon.h"
#include <iostream>
#include <fstream>

void SetOfPokemon::displayList() {
    if (arrayOfPokemon.empty()) {  // Check if the array is empty
        std::cout << "Tu n'as pas de Pokemon" << std::endl;
    } else {
        for(Pokemon * pokemon : arrayOfPokemon){
            std::cout << "******* Attrapez-les tous ! *******" << std::endl;
            pokemon -> displayInfo();
        }
    }
}

int SetOfPokemon::FindByName(string name){
    for (int i=0; i < arrayOfPokemon.size(); i++){
        if (name == arrayOfPokemon.at(i)->getName()){
            return i;
        }

    }
    return 0;
}

int SetOfPokemon::FindById(int id){
    if (id > 721){
        std::cerr << "Numéro de Pokedex introuvable" << std::endl;
        return -1;
    }
    for (size_t i=0; i < arrayOfPokemon.size(); i++){
        if (id == arrayOfPokemon.at(i)-> getId()){
            return static_cast <int> (i);
        }
    }
    return 0;
}

SetOfPokemon::SetOfPokemon(){
}