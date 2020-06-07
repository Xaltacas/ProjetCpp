#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "../Entites/Joueurs/JoueurClavier.hpp"
#include "../Entites/Joueurs/JoueurIA.hpp"
#include "../Entites/Entite.hpp"
#include "../Other/Gamestate.hpp"
#include "../Other/Script.hpp"



/*
Classe principale du jeu
*/
class Jeu {
public:
      //fait tous les calculs sur l'interval de temps dt en paramètre
      void step(int dt);

      //dessine tout le jeu dans la fenètre
      void draw(sf::RenderWindow *window);

      Jeu();

private:

      std::vector<Entite*> Entites;       //listes des entités en jeu
      std::vector<Entite*> EntitesTemp;   //liste temporaires d'entités (utilisée lors des updates pour ne pas modifier la boucle que l'on parcours actuellement)

      Script script;                      //script qui gère les différents evenements du jeu
      struct Gamestate gstate;            //etat instantané du jeu

      sf::Font font;          //police pour l'affichage des informations textuelles
      sf::Text scoreText;     //texte pour afficher le score
      sf::Text perdu;         //texte de fin

      void instantiate();     //fontions appellée en fin de step pour instancier les nouvelles entités
};

#endif
