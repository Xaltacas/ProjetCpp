#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "../Entites/Entite.hpp"
#include "../Entite/Mechant.hpp"
#include "Gamestate.hpp"
#include <stdlib.h>

class Script{

public:
      std::vector<Entite*> instanciateList;

      void update(struct Gamestate *gstate);

      Script():points(0),lastTime(0){};


private:
      double points;
      double lastTime;

      int nbEvent = 10;
      int eventCost[] = {0,10,20,20,30,35,40,40,50,90};

      void event1();
      void event2();
      void event3();
      void event4();
      void event5();
      void event6();
      void event7();
      void event8();
      void event9();


};


#endif
