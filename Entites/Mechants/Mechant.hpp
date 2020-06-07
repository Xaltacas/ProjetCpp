#ifndef MECHANT_HPP
#define MECHANT_HPP

#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"
#include "../Projectiles/Projectile.hpp"


class Mechant: public Entite{
public:
      void update(struct Gamestate *gstate);

      Mechant(Forme* f,Trajectoire* t):Entite(f,ENTITE_MECHANT),traj(t),vie(10),shotCooldown(2),lastShot(0){};

      /*
      ~Mechant(){
            delete(traj);
      }
      */

private:
      Trajectoire* traj;
      int vie;

      double shotCooldown;
      double lastShot;
};

#endif
