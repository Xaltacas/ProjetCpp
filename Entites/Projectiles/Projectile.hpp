#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../../Trajectoires/Trajectoire.hpp"
#include "../Entite.hpp"

/*
Classe représentant un projectile
un projectile est une entité très simple qui ne fait que se déplacer suivant une trajectoir définie
*/

class Projectile: public Entite {
public:
      //methode appellée a chaque cycle
      void update(struct Gamestate *gstate);

      Projectile(Forme* f,Trajectoire* t,int _type):Entite(f,_type),traj(t){};


      ~Projectile(){
            delete traj;
      }


private:
      Trajectoire* traj;      //trajectoire que suis le projectile
};

#endif
