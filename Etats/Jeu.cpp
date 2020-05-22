#include "Jeu.hpp"

void Jeu::step(){
      std::cout << "step" << std::endl;
}

void Jeu::instantiate(){
      std::cout << "instanciate" << std::endl;
}

void Jeu::draw(sf::RenderWindow *window){
      std::cout << "draw" << std::endl;

      sf::CircleShape shape(50.f);
      shape.setFillColor(sf::Color::Green);
      window->draw(shape);

}
