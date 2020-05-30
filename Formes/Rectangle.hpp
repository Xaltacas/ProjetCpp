#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Forme.hpp"
#include "Brique.hpp"

class Rectangle : public Forme {
public:
      Rectangle(double _x, double _y, double _length, double _height, int* _color): Forme(_x,_y,1) {
            briques[0] = Brique(_x-_length/2.,_y-_height/2,_length,_height,_color);
      }

};

#endif
