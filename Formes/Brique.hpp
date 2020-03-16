#ifndef BRIQUE_HPP
#define BRIQUE_HPP

class Brique{
public:
      bool intersect(Brique b);

      double getLength(){return length;};
      double getHeight(){return height;};

      Brique(double _x, double _y, double _length, double _height,int* _color) :
            x(_x),y(_y),length(_length),height(_height) {
                  color[0] = _color[0];
                  color[1] = _color[1];
                  color[2] = _color[2];
      }

private:
      double x;
      double y;

      double length;
      double height;

      int color[3];

};

#endif
