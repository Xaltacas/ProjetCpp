#include "JoueurIA.hpp"

void JoueurIA::update(struct Gamestate *gstate){

      this->traj->update(gstate->dt);

      this->forme->move(this->traj->getX(),this->traj->getY());
};
