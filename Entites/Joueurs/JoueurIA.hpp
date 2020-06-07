#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP
#include "Joueur.hpp"

#include "../../Trajectoires/Trajectoire.hpp"

class JoueurIA : public Joueur{
public:
      void update(struct Gamestate *gstate);

      JoueurIA(Forme* f):Joueur(f),traj(new Trajectoire(0,0,300,0,1.5,0,0,0,0,0)),shotCooldown(0.5),lastShot(0){};


      ~JoueurIA(){
            delete traj;
            delete forme;
      }


private:
      Trajectoire* traj;

      double shotCooldown;
      double lastShot;


};

#endif
