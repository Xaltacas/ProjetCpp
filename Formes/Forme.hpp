#ifndef FORME_HPP
#define FORME_HPP

class Forme{
public:
      virtual bool intersect(Cercle c);
      virtual bool intersect(Rectangle r);

      double getX(){return x};
      double getY(){return y};


private:
      double x;
      double y;


};

#endif
