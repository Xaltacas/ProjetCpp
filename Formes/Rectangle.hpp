#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Forme.hpp"
#include "Brique.hpp"

class Rectangle : public Forme {
public:
      Rectangle(double _x, double _y, double _length, double _height, int[] _color) : Forme(_x,_y) {
            briques = new Brique[1];
            brique[0] = Brique(-_length/2.,-_height/2,_length,_height,_color);
      }

};

#endif
