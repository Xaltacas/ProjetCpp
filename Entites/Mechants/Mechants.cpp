#include "Mechants.hpp"

/*
Implémentation de la logique des trois type de méchants
Toujours le meme schéma:
- mise a jours de la position,
- suppression si la position sort trop du cardre
- tests des collsions pour les degats subit
- test sur les pv pour savoir quand disparaitre
- tir des projetiles si possible
*/

void Mechant1::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);
      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      if( posx < -500 || posx > gstate -> sizeX +500 || posy < -500 || posy > gstate -> sizeY +500){
            gstate -> deleteList[gstate -> currEntity] = true;
            //std::cout << "Mechant OOB : "<< gstate -> currEntity <<  std::endl;
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
      }


      if (gstate -> time - this -> lastShot > this -> shotCooldown)
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr6.txt"),new Trajectoire(0,200,0,0,0,0,0,0,0,0),ENTITE_P_MECHANT));
      }
}

void Mechant2::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);
      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      if( posx < -500 || posx > gstate -> sizeX +500 || posy < -500 || posy > gstate -> sizeY +500){
            gstate -> deleteList[gstate -> currEntity] = true;
            //std::cout << "Mechant OOB : "<< gstate -> currEntity <<  std::endl;
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
            gstate -> score += 25;
      }


      if (gstate -> time - this -> lastShot > this -> shotCooldown)
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr3.txt"),new Trajectoire(0,500,0,0,0,0,0,0,0,0),ENTITE_P_MECHANT));
      }
}

void Mechant3::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);
      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      if( posx < -500 || posx > gstate -> sizeX +500 || posy < -500 || posy > gstate -> sizeY +500){
            gstate -> deleteList[gstate -> currEntity] = true;
            //std::cout << "Mechant OOB : "<< gstate -> currEntity <<  std::endl;
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
            gstate -> score += 50;
      }


      if (gstate -> time - this -> lastShot > this -> shotCooldown)
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr2.txt"),new Trajectoire(-100,300,0,0,0,0,0,0,0,0),ENTITE_P_MECHANT));
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr2.txt"),new Trajectoire(0,300,0,0,0,0,0,0,0,0),ENTITE_P_MECHANT));
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr2.txt"),new Trajectoire(100,300,0,0,0,0,0,0,0,0),ENTITE_P_MECHANT));


      }
}
