cmake_minimum_required(VERSION 3.21)
project(tictactoe)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)


file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

add_executable(tictactoe
        src/main.cpp
        src/pokemon/Pokemon.cpp
        inc/pokemon/Pokemon.h
        src/pokemon/SetOfPokemon.cpp
        inc/pokemon/SetOfPokemon.h
        src/pokemon/InfoConsolePokemon.cpp
        inc/pokemon/InfoConsolePokemon.h
        src/pokemon/Pokedex.cpp
        inc/pokemon/Pokedex.h
        src/pokemon/PokemonParty.cpp
        inc/pokemon/PokemonParty.h
        src/pokemon/PokemonTeam.cpp
        inc/pokemon/PokemonTeam.h
        src/GameEngine.cpp
        inc/GameEngine.h
        src/room/StartersRoom.cpp
        inc/room/StartersRoom.h
        src/room/MenuRoom.cpp
        inc/room/MenuRoom.h
        inc/room/Room.h
        src/Player.cpp
        inc/Player.h
        src/room/InfoConsoleRoom.cpp
        inc/room/InfoConsoleRoom.h
)

target_link_libraries(tictactoe
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)


