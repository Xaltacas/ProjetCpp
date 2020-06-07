#ifndef MECHANT_HPP
#define MECHANT_HPP

#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"
#include "../Projectiles/Projectile.hpp"


class Mechant: public Entite{
public:

      Mechant(Forme* f, Trajectoire* t, int _vie, double shotCD):Entite(f,ENTITE_MECHANT),traj(t),vie(_vie),shotCooldown(shotCD),lastShot(0){};


protected:
      Trajectoire* traj;
      int vie;

      double shotCooldown;
      double lastShot;
};

#endif
