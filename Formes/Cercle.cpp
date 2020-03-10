#include "Cercle.hpp"

bool Cercle::intersect(Cercle c){
      return ((c.getX() - x) * (c.getX() - x)+
		  (c.getY() - y) * (c.getY() - y)
              <= (c.getRayon() + rayon) * (c.getRayon() + rayon));
}

bool Cercle::intersect(Rectangle r){
	double nearestX = Math.max(r.getX(), Math.min(x, r.getX() + r.getLength()));
	double nearestY = Math.max(r.getY(), Math.min(y, r.getY() + r.getHeight()));

	double deltaX = posX - nearestX;
	double deltaY = posY - nearestY;

	return (deltaX * deltaX + deltaY * deltaY) <= (rayon*rayon);

}
