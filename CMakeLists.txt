cmake_minimum_required(VERSION 3.21)
project(tictactoe)
set(CMAKE_CXX_STANDARD 17)

add_executable(tictactoe
        src/main.cpp
        src/Pokemon.cpp
        inc/Pokemon.h
        src/SetOfPokemon.cpp
        inc/SetOfPokemon.h
        src/InfoConsole.cpp
        inc/InfoConsole.h
        src/Pokedex.cpp
        inc/Pokedex.h
)

