#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "../Entites/Entite.hpp"
#include "../Entites/Mechants/Mechant.hpp"
#include "Gamestate.hpp"
#include <stdlib.h>

class Script{

public:
      std::vector<Entite*> instanciateList;

      void update(struct Gamestate *gstate);

      Script():points(10),lastTime(0){
            nbEvent = 12;
            eventCost = new int[nbEvent];
            eventCost[0] = 0;
            eventCost[1] = 10;
            eventCost[2] = 20;
            eventCost[3] = 20;
            eventCost[4] = 30;
            eventCost[5] = 40;
            eventCost[6] = 40;
            eventCost[7] = 50;
            eventCost[8] = 70;
            eventCost[9] = 100;
            eventCost[10] = 5;
            eventCost[11] = 5;
            eventCost[12] = 10;
            eventCost[13] = 10;

      };


private:
      double points;
      double lastTime;

      int nbEvent;
      int *eventCost;

      void event1();
      void event2();
      void event3();
      void event4();
      void event5();
      void event6();
      void event7();
      void event8();
      void event9();
      void event10();
      void event11();
      void event12();
      void event13();


};


#endif
