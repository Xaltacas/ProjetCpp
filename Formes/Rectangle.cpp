#include "Rectangle.hpp"

bool Cercle::intersect(Rectangle r){

	return !((r.getX() + r.getLength() < y)||
               (r.getY() + r.getHeight() < x)||
               (x + length < r.getX())||
               (y + height < r.getY()) );

}
