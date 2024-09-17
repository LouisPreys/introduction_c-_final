//
// Created by louis on 12/09/2024.
//

#ifndef EXERCICEPOKEMON_PLAYER_H
#define EXERCICEPOKEMON_PLAYER_H

#include <string>
#include "Pokemon.h"
#include "PokemonPC.h"
#include "PokemonParty.h"
#include <iostream>
#include "Pokedex.h"

using std::string;

class Player {
private :
    string name;
public :
    Player(string name);
    void displayOpponent();
    std::vector <Pokemon *> opponentPokemon;
    std::vector<Pokemon*> getOpponentPokemon() const;
};

#endif //EXERCICEPOKEMON_PLAYER_H
