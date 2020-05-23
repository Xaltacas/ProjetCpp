#ifndef BRIQUE_HPP
#define BRIQUE_HPP

#include <SFML/Graphics.hpp>

class Brique{
public:
      bool intersect(Brique b);

      void draw(double x,double y,sf::RenderWindow *window);

      Brique(double _x, double _y, double _length, double _height,int* _color) :
            x(_x),y(_y),length(_length),height(_height) {
                  color[0] = _color[0];
                  color[1] = _color[1];
                  color[2] = _color[2];
      }

      Brique(){
            x = 0;
            y = 0;
            length = 0;
            height = 0;

      }

private:
      double x;
      double y;

      double length;
      double height;

      int color[3];

};

#endif
