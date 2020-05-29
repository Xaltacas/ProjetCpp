#ifndef FORME_HPP
#define FORME_HPP

#include "Brique.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Forme{
public:

      Forme(double _x, double _y,int _nbBriques) : x(_x), y(_y),nbBriques(_nbBriques) {
            briques = new Brique[_nbBriques]();
      };
      Forme(double _x, double _y, char* modelpath) : x(_x), y(_y) {
            //todo
      };

      double getX(){return x;};
      double getY(){return y;};

      void move(double x,double y);

      bool intersect(Forme f);

      void draw(sf::RenderWindow *window);


protected:
      double x;
      double y;

      Brique* briques;
      int nbBriques;

};

#endif
