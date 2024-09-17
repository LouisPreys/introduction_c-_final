//
// Created by louis on 09/09/2024.
//

#include "Pokemon.h"
#include <iostream>
#include <algorithm>

int Pokemon::numberofPokemon = 0;
//using namespace Pokemon;

    Pokemon::Pokemon(int id, const string &name, double hitPoint, double attack, double defense,
                     double spattack, double spdefense, double speed, int generation) :
                     id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense),
                     spattack(spattack), spdefense(spdefense), speed(speed), generation(generation) {
        //std::cout << "Ici le constructeur" << std::endl;
        //std::cout << "Id : " << id << std::endl;
        //std::cout << "Nom : " << name << std::endl;
        //std::cout << "HitPoint : " << hitPoint << std::endl;
        //std::cout << "Attack : " << attack << std::endl;
        //std::cout << "Defense : " << defense << std::endl;
        //std::cout << "SpAttack : " << spattack << std::endl;
        //std::cout << "SpDefense : " << spdefense << std::endl;
        //std::cout << "Speed : " << speed << std::endl;
        //std::cout << "Generation : " << generation << std::endl;

        numberofPokemon ++;
    }

    Pokemon::Pokemon(const Pokemon &anotherPokemon) : id(anotherPokemon.id), name(anotherPokemon.name),
                                                      hitPoint(anotherPokemon.hitPoint), attack(anotherPokemon.attack),
                                                      defense(anotherPokemon.defense), spattack(anotherPokemon.spattack),
                                                      spdefense(anotherPokemon.spdefense), speed(anotherPokemon.speed),
                                                      generation(anotherPokemon.generation) {
        //std::cout << "Recopie" << std::endl;

        numberofPokemon ++;
    }

    Pokemon::~Pokemon() {
        std::cout << "Ici le destructeur" << std::endl;

        numberofPokemon --;
    }

void Pokemon::displayInfo(){
    std::cout << "Pokemon #" << id << " : " << name << ", hitPoint : " << hitPoint <<
    ", Attack : " << attack << ", Defense : " << defense << ", SpAttack : " << spattack <<
    ", SpDefense : " << spdefense << ", Speed : " << speed << ", Generation : " << generation << std::endl;
    }

int Pokemon::getId() const {
    return id;
}

const string &Pokemon::getName() const {
    return name;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getGeneration() const {
    return generation;
}
void Pokemon::Pokemonbattle(Pokemon& anotherPokemon) {
    while (hitPoint > 0 && anotherPokemon.hitPoint > 0) {
        // Si votre Pokémon est plus rapide
        if (this->speed >= anotherPokemon.speed) {
            // Votre Pokémon attaque en premier
            attackOpponent(anotherPokemon);  // Fonction d'attaque de votre Pokémon
            if (anotherPokemon.hitPoint <= 0) {
                std::cout << "Tu as gagné !" << std::endl;
                break;
            }
            // L'autre Pokémon riposte
            anotherPokemon.attackOpponent(*this);  // Fonction d'attaque de l'autre Pokémon
            if (hitPoint <= 0) {
                std::cout << "Essaye encore !" << std::endl;
                break;
            }
        }
            // Si l'autre Pokémon est plus rapide
        else {
            // L'autre Pokémon attaque en premier
            anotherPokemon.attackOpponent(*this);  // Fonction d'attaque de l'autre Pokémon
            if (hitPoint <= 0) {
                std::cout << "Essaye encore !" << std::endl;
                break;
            }
            // Votre Pokémon riposte
            attackOpponent(anotherPokemon);  // Fonction d'attaque de votre Pokémon
            if (anotherPokemon.hitPoint <= 0) {
                std::cout << "Tu as gagné !" << std::endl;
                break;
            }
        }
    }
}

// Fonction pour gérer l'attaque d'un Pokémon contre un autre
void Pokemon::attackOpponent(Pokemon& opponent) {
    int damage = 0;
    // Calcul des dégâts physiques ou spéciaux
    if (this->attack >= this->spattack) {
        damage = std::max(0.0, this->attack * 2 - opponent.defense);  // Évite les dégâts négatifs
    } else {
        damage = std::max(0.0, this->spattack * 2 - opponent.spdefense);
    }

    // Appliquer les dégâts
    opponent.hitPoint -= damage;
    std::cout << "PV de " << opponent.name << " : " << opponent.hitPoint << std::endl;
}

int Pokemon::getNumberofPokemon() {
    return numberofPokemon;
}

double Pokemon::getSpeed() const {
    return speed;
}

double Pokemon::getSpattack() const {
    return spattack;
}

double Pokemon::getSpdefense() const {
    return spdefense;
}
