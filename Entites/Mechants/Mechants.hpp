#ifndef MECHANT1_HPP
#define MECHANT1_HPP

#include "Mechant.hpp"

/*
Trois classe concrètes représentant des méchant
Chaque classe a sa propre texture, trajectoire et logique
*/
class Mechant1: public Mechant{
public:
      void update(struct Gamestate *gstate);

      Mechant1(double posx,double posy):Mechant(new Forme(posx,posy,"Formes/Models/M1.txt"),new Trajectoire(0,100,200,0,5,0,0,0,0,0),5,1){};

      ~Mechant1(){
            delete traj;
            delete forme;
      }

};

class Mechant2: public Mechant{
public:
      void update(struct Gamestate *gstate);

      Mechant2(double posx,double posy):Mechant(new Forme(posx,posy,"Formes/Models/M2.txt"),new Trajectoire(200,300,0,0,0,0,0,0,0,0),3,0.7){};

      ~Mechant2(){
            delete traj;
            delete forme;
      }

};

class Mechant3: public Mechant{
public:
      void update(struct Gamestate *gstate);

      Mechant3(double posx,double posy):Mechant(new Forme(posx,posy,"Formes/Models/M3.txt"),new Trajectoire(0,100,200,0,5,0,0,0,0,0),15,3){};

      ~Mechant3(){
            delete traj;
            delete forme;
      }

};




#endif
