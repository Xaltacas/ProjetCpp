# ProjetCpp

Adrien Piednoel
Yann Pouliquen


## Bibliotèques utilisées:

La seule bibliotèque non standard utilisée est SFML 2.4.2


## Compilation:

Un simple make devrait suffire à compiler.
Le makefile contient en comentaire le path vers les bibliotèques SMFL qui marchait sur les ordinateur de l'école.

l'executable créé se nomme "hacode", ./hacode pour lancer le jeu.


## Fonctionnement et but du jeu:

Ce jeu est un space shooter relativement basique, on déplace son personage avec les flèches et l'on tire avec la barre espace.
Le but est d'eviter les projectiles adverses et de survivre le plus longtemps possible.


## Conception du programme:

Ce jeu est concu pour qu'il soit très simple d'instancier et de supprimer des entités (tout objet qui est sujet a une logique (methode update), aux collision et peut etre dessiné) au cours de la partie.
Il est aussi simple de créer un nouveau type d'entité dans le code, pour l'instant il y en a 4 : _Joueur_, _Mechant_, _projectile_(amis et ennemis). Mais n'importe quelle classe héritant de _Entite_ peut etre crée et gérée par le jeu
Actuellement le jeu crée deux joueurs (une IA et un controllé au clavier) en début de partie mais un joueur etant une entité lambda il peut y en avoir n'importe quel nombre (dans la limite du raisonable).

Les textures des différentes entités sont particulière, en effet chaque _Entite_ possède une _Forme_ composée de 0..n _Brique_. Ces Briques sont affichées une à une pour former la Forme. Mais elles ont aussi pour role de detecter les collisions pour savoir si deux formes se chevauchent.  Ce système a été choisis car il nous permettait de developper nos propres texture qui etaint directement liées aux hitbox de nos entités. Ainsi le calcul des collisions peut se faire de manière bien plus fine.


## Organisation au sein du binome:

Pour collaborer sur ce projet nous sommes passé par GIT hébergé sur [gitHub](https://github.com/Xaltacas/ProjetCpp).

Adrien a géré la création du "moteur" du jeu, la hiérarchie entre les différentes classe pour que la classe _Jeu_ puisse gerer sa liste d'entités et que chaque entité de la liste puisse acceder aux information pertinentes de l'etat du jeu.

Yann a géré le coté textures et collisions des différentes entités 
