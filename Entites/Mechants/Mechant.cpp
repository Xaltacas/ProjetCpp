#include "Mechant.hpp"

void Mechant::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);

      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      if( posx < -100 || posx > gstate -> sizeX +100 || posy < -100 || posy > gstate -> sizeY +100){
            gstate -> deleteList[gstate -> currEntity] = true;
            std::cout << "Mechant OOB : "<< gstate -> currEntity <<  std::endl;
      }

      for(int i = 0; i < gstate -> entityCount;i++){
            if(gstate -> collisionMatrix[gstate -> currEntity][i]){
                  if(gstate -> entityType[i] == ENTITE_P_JOUEUR){
                        this -> vie--;
                        gstate -> deleteList[i] = true;
                  }

            }
      }

      if(this -> vie <= 0){
            gstate -> deleteList[gstate -> currEntity] = true;
            gstate -> score += 10;
            //std::cout << "score : "<< gstate -> score <<  std::endl;
      }


      if (gstate -> time - this -> lastShot > this -> shotCooldown)
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr6.txt"),new Trajectoire(0,300,0,0,0,0),ENTITE_P_MECHANT));

      }


}
