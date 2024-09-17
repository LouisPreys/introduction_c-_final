//
// Created by louis on 12/09/2024.
//

#include "Player.h"
#include <algorithm>

Player::Player(std::string name) : name(name) {
    // Assure que l'équipe de l'opposant contient exactement 6 Pokémon
    while (opponentPokemon.size() < 6) {
        int value = rand() % 721; // Génère un ID de Pokémon aléatoire

        Pokemon* encounter = Pokedex::getInstance()->getOnePokemonById(value);
        if (encounter != nullptr) {
            // Vérifie que le Pokémon n'est pas déjà dans la liste pour éviter les doublons
            if (std::find(opponentPokemon.begin(), opponentPokemon.end(), encounter) == opponentPokemon.end()) {
                this->opponentPokemon.push_back(encounter);
            }
        }
    }
}

void Player::displayOpponent() {
    std::cout << "Team de " << name << ":" << std::endl;
    for (Pokemon* p : opponentPokemon) {
        p->displayInfo();
    }
}

std::vector<Pokemon*> Player::getOpponentPokemon() const {
    return opponentPokemon;
}