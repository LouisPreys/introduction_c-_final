//
// Created by louis on 09/09/2024.
//
#ifndef EXERCICEPOKEMON_A_H
#define EXERCICEPOKEMON_A_H

#include <string>

//namespace Pokemon {

    using std::string;

    class Pokemon {
    private :
        int id;
        string name;
        double hitPoint;
        double attack;
        double defense;
        double spattack;
        double spdefense;
        double speed;
        int generation;
        static int numberofPokemon; //seul cette classe peut modifier le nombre de Pokemon
    public :
        Pokemon() = delete;
        Pokemon(int id, const string &name, double hitPoint, double attack, double defense,
                double spattack, double spdefense, double speed, int generation);
        Pokemon(const Pokemon &anotherPokemon);
        void displayInfo();
        int getId() const;
        const string &getName() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;
        double getSpattack() const;
        double getSpdefense() const;
        double getSpeed() const;
        int getGeneration() const;
        static int getNumberofPokemon();
        void Pokemonbattle(Pokemon & anotherPokemon);
        void attackOpponent(Pokemon& opponent);
        ~Pokemon();
    };
//}

#endif //EXERCICEPOKEMON_A_H