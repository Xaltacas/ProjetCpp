#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP


#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"

class Projectile: public Entite {
public:
      void update(struct Gamestate *gstate);

      Projectile(Forme* f,Trajectoire* t,int _type):Entite(f,_type),traj(t){};


      ~Projectile(){
            delete traj;
      }


private:
      Trajectoire* traj;
};

#endif
