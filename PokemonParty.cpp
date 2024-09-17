//
// Created by louis on 12/09/2024.
//

#include "PokemonParty.h"
#include <iostream>
#include <algorithm>

PokemonParty::PokemonParty(){

}

/*PokemonParty::PokemonParty(std::vector<Pokemon*>& capturedPokemon) {
    battlePokemon.clear();  // Vider l'équipe actuelle
    int chosenIndex;
    int count = 0;

    if (capturedPokemon.empty()) {
        std::cout << "Vous n'avez capture aucun Pokémon." << std::endl;
        return;
    }

    // Afficher les Pokémon capturés avec leurs index
    std::cout << "Selectionnez 6 Pokemon pour votre equipe de combat : " << std::endl;
    for (size_t i = 0; i < capturedPokemon.size(); ++i) {
        std::cout << i + 1 << ": ";
        capturedPokemon[i]->displayInfo();
    }

    // Demander au joueur de sélectionner les Pokémon par leur index
    while (count < 6 && count < capturedPokemon.size()) {
        std::cout << "Choisissez un Pokemon par son numero (entre 1 et " << capturedPokemon.size() << ") : ";
        std::cin >> chosenIndex;

        // Vérification que l'index est valide
        if (chosenIndex < 1 || chosenIndex > static_cast<int>(capturedPokemon.size())) {
            std::cout << "Numero invalide, veuillez reessayer." << std::endl;
            continue;
        }

        // Vérifier si le Pokémon a déjà été sélectionné
        Pokemon* selectedPokemon = capturedPokemon[chosenIndex - 1];
        if (std::find(battlePokemon.begin(), battlePokemon.end(), selectedPokemon) != battlePokemon.end()) {
            std::cout << "Vous avez deja selectionne ce Pokemon. Choisissez-en un autre." << std::endl;
            continue;
        }

        // Ajouter le Pokémon sélectionné à l'équipe de combat
        battlePokemon.push_back(selectedPokemon);
        std::cout << selectedPokemon->getName() << " a ete ajoute a votre equipe de combat !" << std::endl;
        count++;
    }

    if (battlePokemon.size() == 6) {
        std::cout << "Votre equipe de combat est maintenant complete !" << std::endl;
    } else {
        std::cout << "Vous avez sélectionne " << battlePokemon.size() << " Pokemon." << std::endl;
    }
}*/

void PokemonParty::displayParty() const {
    if (battlePokemon.empty()) {
        std::cout << "Vous n'avez pas de Pokémon dans votre équipe de combat." << std::endl;
    } else {
        std::cout << "********* Equipe Pokemon *********" << std::endl;
        for (Pokemon* pokemon : battlePokemon) {
            pokemon->displayInfo();
        }
    }
}

void PokemonParty::chooseBattlePokemon(std::vector<Pokemon*>& capturedPokemon, int numToChoose) {
    battlePokemon.clear();  // Vider l'équipe actuelle

    if (capturedPokemon.empty()) {
        std::cout << "Vous n'avez capture aucun Pokemon." << std::endl;
        return;
    }

    std::cout << "Choisissez " << numToChoose << " Pokemon parmi les captures :" << std::endl;

    // Afficher les Pokémon capturés avec leurs index
    for (size_t i = 0; i < capturedPokemon.size(); ++i) {
        std::cout << i + 1 << ": " << capturedPokemon[i]->getName() << std::endl;
    }

    int choice;
    while (battlePokemon.size() < numToChoose) {
        std::cout << "Quel Pokemon voulez-vous ajouter a votre equipe ? (Numero entre 1 et " << capturedPokemon.size() << ") : ";
        std::cin >> choice;

        // Vérifier si le choix est valide
        if (choice < 1 || choice > static_cast<int>(capturedPokemon.size())) {
            std::cout << "Choix invalide. Essayez a nouveau." << std::endl;
            continue;
        }

        // Vérifier si le Pokémon a déjà été sélectionné
        Pokemon* selectedPokemon = capturedPokemon[choice - 1];
        if (std::find(battlePokemon.begin(), battlePokemon.end(), selectedPokemon) != battlePokemon.end()) {
            std::cout << "Vous avez deje selectionne ce Pokémon. Choisissez-en un autre." << std::endl;
            continue;
        }

        // Ajouter le Pokémon sélectionné à l'équipe de combat
        battlePokemon.push_back(selectedPokemon);
        std::cout << selectedPokemon->getName() << " a ete ajoute a votre equipe de combat !" << std::endl;

        // Si le nombre de Pokémon choisis est atteint
        if (battlePokemon.size() == numToChoose) {
            std::cout << "Vous avez choisi " << numToChoose << " Pokemon. Votre equipe est complete !" << std::endl;
            break;
        }
    }
}


void PokemonParty::RemovePokemonFromPartybyName(std::vector<Pokemon*>& capturedPokemon, string name, int i){
    Pokemon* onepokemon = battlePokemon.at(i);
    capturedPokemon.push_back(onepokemon);
    std::cout << "Au revoir " << onepokemon -> getName() << std::endl;
}

void PokemonParty::disband(std::vector <Pokemon *> capturedPokemon) {
    std::cout << "********* Retour dans le PC **********" << std::endl;
    for (Pokemon* p : battlePokemon) {
        linkedPokeball ->addPokemon(p, capturedPokemon);
        std::cout << p ->getName() << " est dans le PC" << std::endl;
    }
    battlePokemon.clear();
}

const std::vector<Pokemon*>& PokemonParty::getBattlePokemon() const {
    return battlePokemon;
}

PokemonParty::~PokemonParty(){

}

Pokemon *PokemonParty::getOnePokemonByName(string name) {
    int IndexInList = this -> FindByName(name);
    if (IndexInList!=-1) {
        Pokemon* pokemon = arrayOfPokemon.at(IndexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+IndexInList);
        return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
    }
    return nullptr;
}

Pokemon *PokemonParty::getOnePokemonById(int id) {
    if (id>0 && id<=721) {
        Pokemon *pokemon = nullptr;
        int IndexInList = this->FindById(id);
        if (IndexInList != -1) {
            Pokemon *pokemon = arrayOfPokemon.at(IndexInList);
            arrayOfPokemon.erase(arrayOfPokemon.begin() + IndexInList);
            return pokemon; //On utilise le constructeur de copie (qui a besoin d'un Pokemon, pas de son adresse), et on récupère le Pokemon souhaité à son adresse puis on le déréférence et on le renvoie
        }
    }
    return nullptr;
}