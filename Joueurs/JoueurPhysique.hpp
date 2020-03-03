#ifndef JOUEURP_HPP
#define JOUEURP_HPP
#include "Joueur.hpp"

class JoueurPhysique : public Joueur{
public:
      void updatePos();
      void actions();

};

#endif
