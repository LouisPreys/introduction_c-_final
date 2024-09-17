cmake_minimum_required(VERSION 3.23)
project(ExercicePokemon)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExercicePokemon main.cpp Pokemon.cpp SetOfPokemon.cpp Pokedex.cpp PokemonPC.cpp PokemonParty.cpp Game.cpp Player.cpp)
