#include "JoueurIA.hpp"

void JoueurIA::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);

      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      for(int i = 0; i < gstate -> entityCount;i++){
            if(gstate -> collisionMatrix[gstate -> currEntity][i]){
                  if(gstate -> entityType[i] == ENTITE_P_MECHANT){
                        this -> vie--;
                        gstate -> deleteList[i] = true;
                  }

            }
      }

      if(this -> vie <= 0){
            gstate -> deleteList[gstate -> currEntity] = true;
            gstate -> alivePlayer--;
      }

      if (gstate -> time - this -> lastShot > this -> shotCooldown)
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr5.txt"),new Trajectoire(0,-300,0,0,0,0),ENTITE_P_JOUEUR));

      }

};
