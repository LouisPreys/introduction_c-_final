#include <iostream>
#include "Pokemon.h"
#include "Pokedex.h"
#include "SetOfPokemon.h"
#include "PokemonPC.h"
#include "PokemonParty.h"
#include "Game.h"
#include "Player.h"

int main() {
    srand (time(NULL));
    std::cout << "Pokemon test" << std::endl;

    //Pokemon Mewtwo(150,"Mewtwo",1000,100,100,150,130,140,1);
    //Pokemon p2(Mewtwo);
    //Pokemon Simiabraz(392,"Simiabraz",350,120,80,120, 80, 130,4);
    //Pokemon Cotovol(210, "Cotovol", 100, 20, 30, 10, 20, 40, 2);
    //Pokemon Levaurien(680, "Levaurien", 1000, 120, 60, 100, 80, 200, 8);
    //Mewtwo.Pokemonbattle(Cotovol);
    //Levaurien.Pokemonbattle(Cotovol);

    std::cout << "Nombre de Pokemon en memoire : " << Pokemon::getNumberofPokemon() << std::endl;

    Pokedex* pokedex = Pokedex::getInstance();

    std::cout << "Nombre de Pokemon en memoire : " << Pokemon::getNumberofPokemon() << std::endl;

    // Créer une instance de PokemonPC
    PokemonPC myPokemonPC;

    // Créer un vecteur pour stocker les Pokémon capturés
    std::vector<Pokemon*> capturedPokemon;

    Pokemon* newPokemon = Pokedex::getInstance()->getOnePokemonById(rand() % 721);
    if (newPokemon != nullptr) {
        myPokemonPC.addPokemon(newPokemon, capturedPokemon);
    }

    // Exemple d'obtention et affichage des Pokémon capturés
    std::vector<Pokemon*> myCapturedPokemon = myPokemonPC.getCapturedPokemon(capturedPokemon);
    std::cout << "Pokemon captures :" << std::endl;
    for (Pokemon* pokemon : myCapturedPokemon) {
        pokemon->displayInfo();
    }

    /*PokemonPC* pokeball= new PokemonPC();
    pokeball -> displayList();
    pokeball -> EncounterPokemon(capturedPokemon);
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> EncounterPokemon();
    pokeball -> displayList();

    myparty.displayParty();
    myparty.disband();
    myparty.displayParty();

    myparty.displayList();
    pokeball->displayList();
    myparty.disband();*/

    Game game;  // Création d'une instance de Game
    game.startGame(capturedPokemon);  // Démarrer le jeu

    return 0;
}
