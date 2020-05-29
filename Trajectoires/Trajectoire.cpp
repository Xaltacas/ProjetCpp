#include "Trajectoire.hpp"
#include <math.h>

void Trajectoire::update(int dt){
      double moveX = 0;
      double moveY = 0;

      double ft = 0.001*dt;
      this -> temps += ft;

      moveX += this -> affX *ft;
      moveY += this -> affY *ft;

      moveX += ft* this->ampSinX * sin(this->freqSinX * this -> temps);
      moveY += ft* this->ampSinY * sin(this->freqSinY * this -> temps);

      this -> nextX = moveX;
      this -> nextY = moveY;

}
