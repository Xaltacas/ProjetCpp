#ifndef MECHANT_HPP
#define MECHANT_HPP

#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"

class Mechant: public Entite{
public:
      void update(struct Gamestate *gstate);

      Mechant(Forme* f,Trajectoire* t):Entite(f),traj(t){};

      /*
      ~Mechant(){
            delete(traj);
      }
      */

private:
      Trajectoire* traj;
      int vie;
};

#endif
