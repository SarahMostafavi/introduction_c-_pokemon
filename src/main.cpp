#include "../inc/pokemon/Pokedex.h"
#include "../inc/GameEngine.h"

int main() {
    Pokedex::getInstance("data/pokedex.csv"); // charge le Pokédex avant toute utilisation

    GameEngine engine;
    engine.run();

    return 0;
}
