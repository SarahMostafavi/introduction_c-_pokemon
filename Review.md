# Revue de code : introduction_c-_pokemon

**Projet relu :** https://github.com/SarahMostafavi/introduction_c-_pokemon/tree/main 
**Auteur :** Sarah Mostafavi Gorji  
**Relecteur :** Fayçal Bouiddouh  
**Date :** 17 septembre 2026

## Compilation et exécution

J’ai eu quelques soucis d'exécution liés aux chemins des fichiers de données. 

Dans `main.cpp`, le Singleton `Pokedex` est instancié avec le chemin relatif `../data/pokedex.csv`. Si on lance l'exécutable depuis le dossier `build`, le programme s'attend à trouver le dossier `data` exactement au même niveau que le dossier `build`. Si l'arborescence est un peu différente (par exemple à cause du clonage Git qui crée un sous-dossier), le programme ne trouve pas le fichier et affiche :

J'ai dû utiliser un chemin absolu ou remonter le dossier `data` à la racine pour que ça fonctionne. Pour éviter ce problème, il serait plus robuste d'utiliser CMake pour copier automatiquement le dossier de données dans le répertoire de compilation.

## Par rapport au sujet

Dans l’ensemble, l'architecture objet demandée par l'exercice est bien présente. L'héritage avec `SetOfPokemon`, le pattern Singleton pour le `Pokedex` et l'encapsulation globale sont respectés.

## Problèmes identifiés

Le premier concerne la mémoire. Dans `main.cpp`, tu crées les Pokémon des joueurs dynamiquement :

```cpp
playerPokemon = new Pokemon(pokedex->getPokemonByName(playerPokemonName));
```

Mais il n'y a aucun `delete playerPokemon;` ni `delete opponentPokemon;` à la fin de la fonction `main`. Aussi, dans `Pokedex.cpp`, tu remplis `arrayOfPokemon` avec des pointeurs fraîchement alloués (`new Pokemon(...)`) lors de la lecture du fichier CSV, mais la classe `Pokedex` n'a pas de destructeur implémenté pour vider ce vecteur à la fin de l'exécution. 

J'ai aussi rencontré un crash immédiat en tapant un nom de Pokémon invalide :

```text
Bonjour, choisissez votre pokemon (nom)
terapagos
terminate called after throwing an instance of 'std::invalid_argument'
```

Si la saisie de l'utilisateur n'est pas strictement identique à celle du fichier, `getPokemonByName` lance une exception `std::invalid_argument`. Comme cette exception n'est pas interceptée par un bloc `try/catch` dans le `main`, le programme plante brutalement au lieu de redemander à l'utilisateur de faire une nouvelle saisie.

## Détails d'implémentation et bonnes pratiques

* **Passage par référence :** Dans `Pokemon.cpp` et `InfoConsole.cpp`, plusieurs types primitifs sont passés par référence constante (ex: `const int &id`, `const double &hitPointMax`). C'est mieux de passer les types primitifs par valeur en C++ pour des raisons de performance.

## Méthode ajoutée : Soin

Pour répondre à la consigne d'ajouter une fonctionnalité, j’ai implémenté une méthode `heal` dans la classe `Pokemon` afin de leur permettre de récupérer de la vie, en s'assurant de ne pas dépasser le maximum :

```cpp
void Pokemon::heal(double amount) {
    if (amount > 0) {
        hitPoint += amount;
        if (hitPoint > hitPointMax) {
            hitPoint = hitPointMax;
        }
        InfoConsole::displayHealInfo(*this, amount);
    }
}
```

## Ce que j’ai bien aimé

L'idée de déporter toute la logique d'affichage dans une classe statique dédiée (`InfoConsole`) est une excellente initiative. Cela allège la classe `Pokemon` et le fichier `main.cpp`.

Le fait de séparer les méthode d'attaque (`attackPokemon`) et de dégâts (`inflictDamageOn`) est aussi une bonne idée pour éviter de surcharger les méthodes.