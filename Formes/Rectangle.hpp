#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "forme.hpp"

class Rectangle : public Forme {
public:
      bool intersect(Cercle c);
      bool intersect(Rectangle r);

      double getLength(){return length};
      double getHeight(){return height};

private:
      double length;
      double height;

};

#endif
