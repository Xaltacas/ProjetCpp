#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Etat.hpp"
#include "../Entites/Joueurs/Joueur.hpp"
#include "../Entites/Mechants/Mechant.hpp"

class Jeu {
public:
      void step();
      void instantiate();
      void draw(sf::RenderWindow *window);

      //Jeu();

private:
      std::vector<Entite> Entites;
      //Script script;
      //Gamestate gamestate;
      int score;
};

#endif
