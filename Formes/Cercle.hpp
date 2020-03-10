#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "forme.hpp"

class Cercle : public Forme {
public:
      bool intersect(Cercle c);
      bool intersect(Rectangle r);

      double getRayon(){return rayon};

private:
      double rayon;

};
#endif
