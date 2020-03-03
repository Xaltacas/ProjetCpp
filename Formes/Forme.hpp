#ifndef FORME_HPP
#define FORME_HPP

class Forme{
public:
      virtual boolean intersect(Cercle c);
      virtual boolean intersect(Rectangle r);

private:
      int x;
      int y;


};

#endif
