![Logo Tetris](./logo_tetris.png)
# Projet Tetris

[![Build & Compile](https://github.com/ThePrincelle/projet-tetris/actions/workflows/build-and-compile.yml/badge.svg)](https://github.com/ThePrincelle/projet-tetris/actions/workflows/build-and-compile.yml)

<br/>

**Membres du binôme :**
- [Hugo Brua](mailto:hbrua@etu.unistra.fr)
- [Maxime Princelle](https://contact.princelle.org)

<br/>

---


## Compiler & Lancer

Pour pouvoir compiler et lancer ce projet, certains applicatifs doivent être installés sur votre machine.

A savoir, seul un environnement Linux est pris en charge pour le moment, en effet la librairie SDL à quelques failles sur les autres OS notamment MacOS.

```bash
sudo apt install cmake gcc g++ libsdl2-dev
```

**Compiler**

```bash
cmake .
make
```

**Lancer**

```bash
./TP_CPP_SDL
```


## Tests automatisés

A chaque commit est exécuté un test afin de vérifier si le code est fonctionnel ou non. 

Ce test est effectué dans l'environnement précisé dans le fichier [Dockerfile](./Dockerfile) est les résultats de ces derniers sont disponibles à cette adresse : 

https://drone.princelle.org/princelle/projet-tetris


## Répartition du travail

| Tâches 	| Hugo 	| Maxime 	|
|-	|:-:	|:-:	|
| Mise en forme des pièces 	| X 	|  	|
| Génération des textures 	|  	| X 	|
| Mouvements des pièces 	| X 	|  	|
| Gestion des collisions 	| X 	|  	|
| Affichage principal 	| X 	|  	|
| Fin de partie (Game Over) 	| X 	| X 	|
| Gestion des inputs de la partie 	| X 	|  	|
| Affichage des informations de partie 	|  	| X 	|
| Tests automatisés 	|  	| X 	|
| Menu principal 	|  	| X 	|
| Documentation 	|  	| X 	|
| Gestion de la vitesse de chute pour les formes 	| X 	|  	|

Pour plus de détails, je vous invite à consulter notre tableau Trello : https://trello.com/b/3N7GDpCV


## Organisation du code

Nous allons ici préciser ce que fait/contient chaque fichier dans l'arborescence.
A noter que l'organisation du code a été conçue de manière à avoir des éléments facilement éditables.

- [block](./block.cpp) : Entité des Blocs, s'occupe des réactations physiques des carrés qui composent les formes. 

- [board](./board.cpp) : Grille du jeu Tetris, elle gère les collisions et les relations entre blocs.

- [form](./form.cpp) : Définit toutes les représentations possibles des pièces (ex: orientation).

- [game](./game.cpp) : Constructeur de la partie (gère le déroulement de la partie, de la création des pièces jusqu'au décompte du temps).

- [main](./main.cpp) : Programme d'entrée pricipal.

- [menu](./menu.cpp) : Gère le menu principal.

- [piece](./piece.cpp) : Définit les caractéristiques d'une pièce (couleur, forme, etc...)

- [pieceBag](./pieceBag.cpp) : Gère les pièces suivantes dans le déroulement d'une partie.

- [sprite](./sprite.cpp) : Gère l'extraction des surfaces d'un fichier BMP à travers 'surface' pour une réutilisation ultérieure

- [surface](./surface.cpp) : Charge les fichiers BMP

- [timer](./timer.cpp) : Permet de générer des "Ticks" sans déranger le bon déroulement du code principal.

- [vec2](./vec2.cpp) : Objet définissant un vecteur à deux dimensions (création, opérations, etc...).

- [window_surface](./window_surface.cpp) : Permet de prendre une texture de type 'sprite' pour la déposer sur une fenêtre.


## Difficultés rencontrées

- Implémentation de la librairie SDL_txt
> Après de multiples tentatives, il se trouve que pour intégrer du texte, il nous faut utiliser un Renderer avec SDL. Or, ce dernier n'a pas été implémenté dès le départ.

- Utilisation impossible de plusieurs surfaces
> Au sein d'une même instance de Game, il nous est impossible de charger de multiples surfaces provenant de fichiers BMP différents. La solution à ça a été de mettre toutes les textures au sein d'un seul même fichier.

- Collision des pièces
> Le problème venait du tableau contenant les informations des cases de la grille. En effet, les calculs effectués depuis ces derniers engendraient des conflits entre les pièces indiquées dans le tableau et les vraies formes.

- Gestion du sommet du bac
> Pour contourner le problème, nous avons créé un tableau contenant la hauteur de chaque colonne sur la grille, une vérification est faite à chaque pose d'une forme, si on dépasse la grille, le jeu se ferme.


## Fonctionnalités futures

- Mode 1V1
- Jouer contre l'ordinateur (IA)
- Ajout de textes (voir branche: text_implementation)
