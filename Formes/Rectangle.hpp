#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "forme.hpp"

class Cercle : public Forme {
public:
      boolean intersect(Cercle c);
      boolean intersect(Rectangle r);

private:
      int rayon;

};

#endif
