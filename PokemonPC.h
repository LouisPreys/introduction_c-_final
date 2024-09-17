//
// Created by louis on 11/09/2024.
//

#ifndef EXERCICEPOKEMON_POKEMONPC_H
#define EXERCICEPOKEMON_POKEMONPC_H

#include "SetOfPokemon.h"

class PokemonPC : public SetOfPokemon{
protected :
public :
    PokemonPC();
    Pokemon *getOnePokemonByName(string name);
    Pokemon *getOnePokemonById(int id);
    PokemonPC(const Pokemon &anotherPokemon);
    void EncounterPokemon(std::vector<Pokemon*>& capturedPokemon);
    void addPokemon(Pokemon* pokemon, std::vector<Pokemon*>& capturedPokemon);
    const std::vector<Pokemon*> getCapturedPokemon(std::vector<Pokemon*>& capturedPokemon);
};

#endif //EXERCICEPOKEMON_POKEMONPC_H
