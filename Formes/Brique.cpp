#include "Brique.hpp"

bool Cercle::intersect(Brique b){

	return !((b.x + b.lenght < y)||
               (b.y + b.height < x)||
               (x + length < b.x)||
               (y + height < b.y) );

}
