#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "Forme.hpp"
#include "Brique.hpp"

class Cercle : public Forme {
public:
      Cercle(double _x, double _y, double _radius, int* _color): Forme(_x,_y,3) {

            briques[0] = Brique(-_radius,-_radius/3,2*_radius,2*_radius/3,_color);
            briques[1] = Brique(-8*_radius/9,-8*_radius/9,16*_radius/9,16*_radius/9,_color);
            briques[2] = Brique(-_radius/3,-_radius,2*_radius/3,2*_radius,_color);
      }

};

#endif
