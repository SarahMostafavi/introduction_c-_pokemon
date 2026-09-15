# introduction_c++_pokemon

Pour jouer au jeu il faut écrire dans la console le nom du pokemon que le joueur choisis, puis le nom du pokemon de son adversaire.
Ensuite les pokemons commencent à s'attaquer chacun leur tour jusqu'à ce qu'un des deux meurt.


## Avancée du jeu
Je n'ai pas réussi à mettre en place le framework SFML donc le jeu se fait uniquement sur console.
Le pokedex fonctionne et utilise le design pattern Singleton.


## Diagramme de classe
Il y a la classe **Pokemon** qui définit les caractéristques d'un pokemon.
Elle contient :
* une méthode publique inflictDamageOn qui permet d'infliger les dégats attaque-defense à un autre pokemon et de mettre à jour l'état du pokemon attaqué.
* une méthode publique attackPokemon qui permet au pokemon de lancer une attaque sur un autre pokemon indiqué en paramètre. 

La classe **InfoConsole** permet d'afficher les informations d'un pokemon ou les informations sur l'attaque d'un autre pokemon. Elle utilise donc la classe pokemon.

La classe **SetOfPokemon** est abstraite et définis de méthodes abstraites qui permettent de récupérer des pokemon et deux méthodes concrêtes qui permettent d'afficher les informations des pokemons indiqués dans un vector de nom ou d'id de pokemons.
La classe utilise la classe **Pokemon**.

La classe **Pokedex** hérite de la classe abstraite **SetOfPokemon**. Elle utilise le design pattern singleton car on ne veut qu'une seule instance du Pokedex.
Elle implémente les deux méthodes abstraites de **SetOfPokemon** qui permettent de créer des copies de Pokemons présent dans le Pokedex.
Elle utilise la classe **Pokemon**.