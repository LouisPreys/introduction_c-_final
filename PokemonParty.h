//
// Created by louis on 12/09/2024.
//

#ifndef EXERCICEPOKEMON_POKEMONPARTY_H
#define EXERCICEPOKEMON_POKEMONPARTY_H

#include "SetOfPokemon.h"
#include "PokemonPC.h"

class PokemonParty : public SetOfPokemon{
private :
    static const int MAX_SIZE = 6;
    std::vector <Pokemon *> battlePokemon;
    PokemonPC* linkedPokeball;
public :
    PokemonParty();
    //PokemonParty(std::vector<Pokemon*>& capturedPokemon);
    void displayParty() const;
    Pokemon* getOnePokemonByName(string name);
    Pokemon* getOnePokemonById(int id);
    void disband(std::vector <Pokemon *> capturedPokemon);
    void chooseBattlePokemon(std::vector<Pokemon*>& capturedPokemon, int number);
    void RemovePokemonFromPartybyName(std::vector<Pokemon*>& capturedPokemon, string name, int i);
    const std::vector<Pokemon*>& getBattlePokemon() const;
    ~PokemonParty();

    void RemovePokemonFromPartybyName(string name, int i);
};

#endif //EXERCICEPOKEMON_POKEMONPARTY_H
