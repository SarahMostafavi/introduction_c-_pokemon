cmake_minimum_required(VERSION 3.21)
project(tictactoe)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(SFML)


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
        src/PokemonTeam.cpp
        inc/PokemonTeam.h
        src/Player.cpp
        inc/Player.h
)

target_link_libraries(tictactoe PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)


