#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Etat.hpp"
#include "../Entites/Joueurs/JoueurPhysique.hpp"
#include "../Entites/Joueurs/JoueurIA.hpp"
#include "../Entites/Mechants/Mechant.hpp"
#include "../Entites/Entite.hpp"
#include "../Other/Gamestate.hpp"
#include "../Other/Script.hpp"

class Jeu {
public:
      void step(int dt);
      void draw(sf::RenderWindow *window);

      Jeu();

private:
      std::vector<Entite*> Entites;
      Script script;
      struct Gamestate gstate;
      int score;

      void instantiate();
};

#endif
