#include "Projectile.hpp"

void Projectile::update(struct Gamestate *gstate){

      //mise  jours de la position
      this->traj->update(gstate->dt);
      this->forme->move(this->traj->getX(),this->traj->getY());

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      //supprésion si on sort trop du cadre
      if( posx < -100 || posx > gstate -> sizeX +100 || posy < -100 || posy > gstate -> sizeY +100){
            gstate -> deleteList[gstate -> currEntity] = true;
            //std::cout << "Projectile OOB : "<< gstate -> currEntity <<  std::endl;
      }



}
