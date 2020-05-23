#ifndef FORME_HPP
#define FORME_HPP

#include "Brique.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Forme{
public:

      Forme(double _x, double y,int _nbBriques) : x(_x), y(_x),nbBriques(_nbBriques) {
            briques = new Brique[_nbBriques]();
      };
      Forme(double _x, double y, char* modelpath) : x(_x), y(_x) {
            //todo
      };

      double getX(){return x;};
      double getY(){return y;};

      bool intersect(Forme f);

      void draw(sf::RenderWindow *window);


protected:
      double x;
      double y;

      Brique* briques;
      int nbBriques;

};

#endif
