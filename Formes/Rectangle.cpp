#include "Rectangle.hpp"

bool Cercle::intersect(Cercle c){
      double nearestX = Math.max(x, Math.min(c.getX(), x + length));
	double nearestY = Math.max(y, Math.min(c.getY(), y + height));

	double deltaX = c.getX() - nearestX;
	double deltaY = c.getY() - nearestY;

	return (deltaX * deltaX + deltaY * deltaY) <= (c.getRayon() * c.getRayon());
}

bool Cercle::intersect(Rectangle r){

	return !((r.getX() + r.getLength() < y)||
               (r.getY() + r.getHeight() < x)||
               (x + length < r.getX())||
               (y + height < r.getY()) );

}
