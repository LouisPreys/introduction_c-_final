//
// Created by louis on 12/09/2024.
//

#ifndef EXERCICEPOKEMON_GAME_H
#define EXERCICEPOKEMON_GAME_H

#include "Pokemon.h"
#include "SetOfPokemon.h"
#include "PokemonParty.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

// États possibles du jeu
enum State {
    INIT,
    START,
    EXPLORATION,
    ARENE,
    VICTOIRE,
    DEFAITE
};

class Game {
private:
    std::vector<Pokemon*> battlePokemon;
    std::vector <Pokemon *> opponentPokemon;
    State currentState;

public:
    Game();  // Constructeur
    void chooseName();
    void chooseStarter(std::vector<Pokemon*>& capturedPokemon);
    void exploration(std::vector<Pokemon*>& capturedPokemon);
    void arene();
    void victoire(std::vector<Pokemon*> capturedPokemon);
    void defaite(std::vector<Pokemon*> capturedPokemon);
    State getState() const;
    void update();  // Méthode pour mettre à jour le jeu en fonction de l'état actuel
    void startGame(std::vector<Pokemon*>& capturedPokemon);
};

#endif //EXERCICEPOKEMON_GAME_H
