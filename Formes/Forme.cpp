#include "Forme.hpp"

void Forme::move(double x,double y){
      this->x += x;
      this->y += y;
}

bool Forme::intersect(Forme f){
      for(int i = 0; i < this->nbBriques; i++){
            for(int j = 0; j < f.nbBriques; j++){
                  if(this->briques[i].intersect(f.briques[j]))
                        return true;
            }
      }

      return false;
}

void Forme::draw(sf::RenderWindow *window){
      for(int i = 0; i < nbBriques; i++){
            briques[i].draw(this->x,this->y,window);
      }
}
