#include "Forme.hpp"

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
      std::cout << "draw" << std::endl;
      for(int i = 0; i < nbBriques; i++){
            briques[i].draw(this->x,this->y,window);
      }
}
