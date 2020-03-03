#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "forme.hpp"

class Cercle : public Forme {
public:
      boolean intersect(Cercle c);
      boolean intersect(Rectangle r);


private:
      int rayon;

};
#endif
