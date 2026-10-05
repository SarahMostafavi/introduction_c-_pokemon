#include "../inc/pokemon/Pokedex.h"
#include "../inc/GameEngine.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Pokedex::getInstance("data/pokedex.csv"); // charge le Pokédex avant toute utilisation

    GameEngine engine;
    engine.run();

    return 0;
}
