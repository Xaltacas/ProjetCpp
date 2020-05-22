#ifndef FORME_HPP
#define FORME_HPP

#include "Brique.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Forme{
public:

      Forme(double _x, double y) : x(_x), y(_x) {};
      Forme(double _x, double y, char* modelpath) : x(_x), y(_x) {
            //todo
      };

      double getX(){return x;};
      double getY(){return y;};

      bool intersect(Forme f);

      void draw(sf::RenderWindow *window);


private:
      double x;
      double y;

      Brique* briques;
      int nbBriques;

};

#endif
