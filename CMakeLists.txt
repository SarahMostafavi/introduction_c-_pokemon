cmake_minimum_required(VERSION 3.21)
project(tictactoe)
set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

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
        src/PokemonParty.cpp
        inc/PokemonParty.h
)

