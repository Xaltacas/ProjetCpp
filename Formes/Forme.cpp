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
