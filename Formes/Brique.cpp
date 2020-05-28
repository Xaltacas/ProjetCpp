#include "Brique.hpp"

bool Brique::intersect(Brique b){

	return !((b.x + b.length < y)||
               (b.y + b.height < x)||
               (x + length < b.x)||
               (y + height < b.y) );

}


void Brique::draw(double x, double y,sf::RenderWindow *window){
	sf::RectangleShape rect(sf::Vector2f(this->length,this->height));
	rect.setPosition(x + this -> x, y + this -> y);
	rect.setFillColor(sf::Color(this->color[0],this->color[1],this->color[2]));
	window->draw(rect);
}
