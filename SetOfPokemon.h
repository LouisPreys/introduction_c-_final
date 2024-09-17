//
// Created by louis on 09/09/2024.
//

#ifndef EXERCICEPOKEMON_SETOFPOKEMON_H
#define EXERCICEPOKEMON_SETOFPOKEMON_H

#include "Pokemon.h"
#include <vector>
#include <string>

using std::string;

class SetOfPokemon {
protected :
    std::vector <Pokemon *> arrayOfPokemon;
public :
    virtual Pokemon * getOnePokemonByName(string name)=0;
    virtual Pokemon * getOnePokemonById(int id)=0;
    int FindByName(string name);
    int FindById(int id);
    void displayList();
    SetOfPokemon();

    //virtual ~SetOfPokemon()=0;
};

#endif //EXERCICEPOKEMON_SETOFPOKEMON_H
