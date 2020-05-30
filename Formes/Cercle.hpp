#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "Forme.hpp"
#include "Brique.hpp"

class Cercle : public Forme {
public:
      Cercle(double _x, double _y, double _radius, int* _color): Forme(_x,_y,1) {
            briques[0] = Brique(_x,_y,radius*4/3,radius*4/3,_color);
            briques[1] = Brique(_x,_y,radius*2,radius*2/3,_color);
            briques[2] = Brique(_x,_y,radius*2/3,radius,_color);
      }

};

#endif
