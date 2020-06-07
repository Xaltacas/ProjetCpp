#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include "../Entites/Entite.hpp"
#include "../Entites/Mechants/Mechants.hpp"
#include "Gamestate.hpp"
#include <stdlib.h>


/*
Classe qui gère les différent  evenement au cours de la partie (vitesse et type d'apparition de mechants)
*/
class Script{
public:
      //liste des unités à instancier
      std::vector<Entite*> instanciateList;

      //fonction appellée à chaque cycle
      void update(struct Gamestate *gstate);


      Script():points(10),lastTime(0){
            nbEvent = 12;
            eventCost = new int[nbEvent];
            eventCost[0] = 0;
            eventCost[1] = 10;
            eventCost[2] = 20;
            eventCost[3] = 20;
            eventCost[4] = 30;
            eventCost[5] = 30;
            eventCost[6] = 30;
            eventCost[7] = 50;
            eventCost[8] = 70;
            eventCost[9] = 100;
            eventCost[10] = 110;
            eventCost[11] = 120;
      };


private:
      double points;    //les points sont une manière de représenter la menace de sorte à ce que la difficultée augment au cours de la partie
      double lastTime;  //dernière fois qu'un event a eu lieu

      int nbEvent;      //nb d'evenement différents
      int *eventCost;   //liste du cout des différents evenements

      //différents evenements
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



};


#endif
