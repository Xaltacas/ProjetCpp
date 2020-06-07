#ifndef MECHANT_HPP
#define MECHANT_HPP

#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"
#include "../Projectiles/Projectile.hpp"

/*
Classe abstraite représantant un méchant
*/
class Mechant: public Entite{
public:

      Mechant(Forme* f, Trajectoire* t, int _vie, double shotCD):Entite(f,ENTITE_MECHANT),traj(t),vie(_vie),shotCooldown(shotCD),lastShot(0){};


protected:
      Trajectoire* traj;      //trajectoire que suit le méchant
      int vie;                //points de vie

      double shotCooldown;    //delai entre deux tirs
      double lastShot;        //temps du denrier tir
};

#endif
