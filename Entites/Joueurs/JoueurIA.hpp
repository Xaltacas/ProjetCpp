#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP
#include "Joueur.hpp"

#include "../../Trajectoires/Trajectoire.hpp"

class JoueurIA : public Joueur{
public:
      void update(struct Gamestate *gstate);

      JoueurIA(Forme* f):Joueur(f),traj(new Trajectoire(0,0,300,0,1.5,0)){};

private:
      Trajectoire* traj;


};

#endif
