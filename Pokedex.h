//
// Created by louis on 09/09/2024.
//

#ifndef EXERCICEPOKEMON_POKEDEX_H
#define EXERCICEPOKEMON_POKEDEX_H

#include "SetOfPokemon.h"

class Pokedex : virtual public SetOfPokemon{
private :
    Pokedex(string name);
    static Pokedex * instance; //static lié à la classe
public :
    static Pokedex * getInstance();
    Pokemon * getOnePokemonByName(string name);
    Pokemon * getOnePokemonById(int id);
    ~Pokedex();
};

#endif //EXERCICEPOKEMON_POKEDEX_H
