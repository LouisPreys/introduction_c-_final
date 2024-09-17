//
// Created by louis on 12/09/2024.
//

#include "Game.h"
#include "SetOfPokemon.h"
#include "Pokemon.h"
#include "Pokedex.h"

// Variables globales
State currentState = INIT;  // État initial
std::vector <Pokemon *> battlePokemon; //Pokemon de combat
std::string starterPokemon;

Game::Game() {
    // Initialisation de Game
}

void Game::chooseName() {
    std::string playerName;
    std::cout << "Entrez votre nom : ";
    std::cin >> playerName;
}

// Fonction pour choisir un Pokémon de départ
void Game::chooseStarter(std::vector<Pokemon*>& capturedPokemon) { //problème : si on met un nom qui n'existe pas dans le pokedex, cette fonction renvoie automatiquement bulbizarre, le premier pokémon du pokedex
    while (true) {  // Boucle infinie jusqu'à ce qu'un Pokémon valide soit trouvé
        std::cout << "Qui sera ton premier compagnon ? ";
        std::cin >> starterPokemon;

        // Cherche le Pokémon dans le Pokedex
        Pokemon *starter = Pokedex::getInstance()->getOnePokemonByName(starterPokemon);

        // Vérifie si le Pokémon a été trouvé
        if (starter == nullptr) {
            std::cout << "Le Pokemon " << starterPokemon << " n'existe pas dans le Pokedex. Essayez encore." << std::endl;
        }
        else {
            // Ajoute le Pokémon capturé à la liste
            capturedPokemon.push_back(starter);
            starter->displayInfo();
            std::cout << starter->getName() << " est ton premier Pokemon !" << std::endl;
            break;  // Sort de la boucle lorsque le Pokémon est trouvé
        }
    }
}

// Fonction pour rencontrer et capturer des Pokémon sauvages
void Game::exploration(std::vector<Pokemon*>& capturedPokemon) {
    std::cout << "Tu es en exploration..." << std::endl;

    int steps = 0;
    while (capturedPokemon.size() < 10) { // Continue jusqu'à capturer 10 Pokémon
        ++steps;

        if (steps % 2 == 0) { // Rencontrer un Pokémon tous les deux pas
            std::cout << "Vous marchez dans les hautes herbes..." << std::endl;

            // Rencontre un Pokémon sauvage
            PokemonPC pokemonPc;
            pokemonPc.EncounterPokemon(capturedPokemon);
        } else {
            std::cout << "Vous continuez a marcher..." << std::endl;
        }
    }

    // Affiche les Pokémon capturés
    std::cout << "Pokemon captures :" << std::endl;
    for (const auto& pokemon : capturedPokemon) {
        pokemon->displayInfo();
    }

    // Demander au joueur de choisir son équipe de combat
    PokemonParty party;
    party.chooseBattlePokemon(capturedPokemon, 6);
    party.displayParty();

    // Vérifier si battlePokemon est complet
    if (party.getBattlePokemon().size() == 6) {
        std::string response;
        std::cout << "Oserez-vous relever le challenge de l'arene ? (y/n) ";
        std::cin >> response;

        if (response == "y" || response == "Y") {
            currentState = ARENE;
        } else {
            currentState = EXPLORATION; // Recommence l'exploration sans perdre les Pokémon capturés
        }
    }
}


// Fonction pour le combat d'arène
void Game::arene() {
    std::cout << "Tu es dans l'arene et affrontes un autre dresseur !" << std::endl;

    // Instancie un objet de la classe Player en utilisant le constructeur Player(string name)
    Player pierre("Pierre, le champion d'arene");
    pierre.displayOpponent();

    // Affrontez les Pokémon du joueur contre ceux de l'adversaire
    for (size_t i = 0; i < battlePokemon.size(); ++i) {
        if (i >= pierre.getOpponentPokemon().size()) break; // Assurez-vous qu'il y a assez de Pokémon adverses

        Pokemon* playerPokemon = battlePokemon[i];
        Pokemon* opponentPokemon = pierre.getOpponentPokemon()[i];

        // Simuler le combat
        playerPokemon->Pokemonbattle(*opponentPokemon);
    }

    // Vérifier combien de Pokémon du joueur ont été vaincus
    int defeatedCount = 0;
    for (Pokemon* pokemon : battlePokemon) {
        if (pokemon->getHitPoint() <= 0) { // Assurez-vous d'avoir une méthode pour obtenir les points de vie
            ++defeatedCount;
        }
    }

    // Passer à l'état victoire ou défaite en fonction du nombre de Pokémon vaincus
    if (defeatedCount >= static_cast<int>(battlePokemon.size()) / 2) {
        currentState = DEFAITE;
        std::cout << "Vous avez perdu le combat. Reprenez l'exploration." << std::endl;
    } else {
        currentState = VICTOIRE;
        std::cout << "Félicitations ! Vous etes le champion !" << std::endl;
    }
}

// Fonction pour afficher l'écran de victoire
void Game::victoire(std::vector<Pokemon*> capturedPokemon) {
    std::cout << "Bravo, tu es le nouveau champion !" << std::endl;
    std::cout << "Appuie sur une touche pour retourner au menu principal..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    currentState = INIT;
    capturedPokemon.clear(); // Réinitialiser les Pokémon capturés
}

// Fonction pour afficher l'écran de défaite
void Game::defaite(std::vector<Pokemon*> capturedPokemon) {
    std::cout << "Tu t'es bien battu ! Retente ta chance !" << std::endl;
    std::cout << "Appuie sur une touche pour retourner au menu principal..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    currentState = INIT;
    capturedPokemon.clear(); // Réinitialiser les Pokémon capturés
}

// Méthodes publiques
void Game::startGame(std::vector<Pokemon*>& capturedPokemon) {
    while (1) {
        char input;
            switch (currentState) {
                case INIT:
                    std::cout << "Es-tu pret pour une nouvelle aventure ? (y : yes / n : no)" << std::endl;
                    std::cin >> input;

                    if (input == 'y') {
                        currentState = START;
                    } else if (input == 'n') {
                        std::cout << "D'accord, a la prochaine !" << std::endl;
                        break;  // Quitte le jeu
                    }
                    break;

                case START:
                    chooseName();
                    chooseStarter(capturedPokemon);
                    currentState = EXPLORATION;
                    break;

                case EXPLORATION:
                    exploration(capturedPokemon);
                    break;

                case ARENE:
                    arene();
                    break;

                case VICTOIRE:
                    victoire(capturedPokemon);
                    break;

                case DEFAITE:
                    defaite(capturedPokemon);
                    break;
            }
    }
}

State Game::getState() const {
    return currentState;
}