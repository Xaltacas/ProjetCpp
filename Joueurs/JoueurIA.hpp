#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP
#include "Joueur.hpp"

class JoueurIA : public Joueur{
public:
      void updatePos();
      void actions();

};

#endif
