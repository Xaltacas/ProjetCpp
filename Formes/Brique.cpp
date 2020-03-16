#include "Brique.hpp"

bool Brique::intersect(Brique b){

	return !((b.x + b.length < y)||
               (b.y + b.height < x)||
               (x + length < b.x)||
               (y + height < b.y) );

}
