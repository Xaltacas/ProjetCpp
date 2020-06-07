#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "Forme.hpp"
#include "Brique.hpp"


//classe derivant de forme, permettant de créer une approximation de cercle sans passer par un fichier de texture
class Cercle : public Forme {
public:
      Cercle(double _x, double _y, double _radius, int* _color): Forme(_x,_y,3) {

            briques[0] = Brique(-_radius,-_radius/3,2*_radius,2*_radius/3,_color);
            briques[1] = Brique(-7*_radius/9,-7*_radius/9,14*_radius/9,14*_radius/9,_color);
            briques[2] = Brique(-_radius/3,-_radius,2*_radius/3,2*_radius,_color);
      }

};

#endif
