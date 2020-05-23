#ifndef JOUEURP_HPP
#define JOUEURP_HPP

#include "Joueur.hpp"

class JoueurPhysique : public Joueur{
public:
      void update();

      JoueurPhysique(Forme* f):Joueur(f){};
};

#endif
