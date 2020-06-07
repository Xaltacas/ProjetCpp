#include "Brique.hpp"
#include <iostream>


bool Brique::intersect(Brique b,int _x1,int _y1,int _x2,int _y2){
	return !((_x2 + b.x + b.length <= x + _x1)||
               (_y2 + b.y + b.height <= y + _y1)||
               (_x1 + x + length <= b.x + _x2)||
               (_y1 + y + height <= b.y + _y2) );
}


void Brique::draw(double x, double y,sf::RenderWindow *window){
	sf::RectangleShape rect(sf::Vector2f(this->length,this->height));
	rect.setPosition(x + this -> x, y + this -> y);
	rect.setFillColor(sf::Color(this->color[0],this->color[1],this->color[2]));
	window->draw(rect);
}
