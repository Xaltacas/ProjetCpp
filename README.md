# ProjetCpp

Adrien Piednoel
Yann Pouliquen


## Bibliotèques utilisées:

La seule bibliotèque non standard utilisée est SFML 2.4.2


## Compilation:

Un simple make devrait suffire à compiler.
Le makefile contient en commentaire le path vers les bibliotèques SMFL qui marchaient sur les ordinateurs de l'école.

l'executable créé se nomme "hacode", ./hacode pour lancer le jeu.


## Fonctionnement et but du jeu:

Ce jeu est un space shooter relativement basique, on déplace son personage avec les flèches et l'on tire avec la barre espace.
Le but est d'eviter les projectiles adverses et de survivre le plus longtemps possible.
On controle le joueur bleu, le joueur rouge est une IA.

La touche échap ferme le jeu.


## Conception du programme:

Ce jeu est concu pour qu'il soit très simple d'instancier et de supprimer des entités (tout objet qui est sujet a une logique (methode update), aux collision et peut etre dessiné) au cours de la partie.
Il est aussi simple de créer un nouveau type d'entité dans le code, pour l'instant il y en a 4 : __Joueur__, __Mechant__, __Projectile__(amis et ennemis). Mais n'importe quelle classe héritant de __Entite__ peut etre crée et gérée par le jeu
Actuellement le jeu crée deux joueurs (une IA et un controllé au clavier) en début de partie mais un joueur etant une entité lambda il peut y en avoir n'importe quel nombre (dans la limite du raisonable).

Les textures des différentes entités sont particulières, en effet chaque __Entite__ possède une __Forme__ composée de 0..n __Brique__. Ces Briques sont affichées une à une pour former la Forme. Mais elles ont aussi pour role de detecter les collisions pour savoir si deux formes se chevauchent.  Ce système a été choisis car il nous permettait de developper nos propres texture qui etant directement liées aux hitbox de nos entités. Ainsi le calcul des collisions peut se faire de manière bien plus fine.

Un main secondaire a été fait pour afficher simplement les texture, compilation avec "make test_texture" et execution ./test_texture

Des tests unitaires ont été réalisés, pour les compiler "make test_main" et execution avec ./test_main


## Organisation au sein du binome:

Pour collaborer sur ce projet nous sommes passé par GIT hébergé sur [gitHub](https://github.com/Xaltacas/ProjetCpp).

Adrien a géré la création du "moteur" du jeu, la hiérarchie entre les différentes classe pour que la classe __Jeu__ puisse gerer sa liste d'entités et que chaque entité de la liste puisse acceder aux information pertinentes de l'etat du jeu.

Yann a géré les textures dans leur création et leur implementation,les collisions des différentes entités au niveau des briques et des formes, le gameplay au niveau des generations d'evenements et de la jouabilité, le game design, la musique et les tests unitaires des collisions.
