#include "Jeu.hpp"

void Jeu::step(int dt){
      this -> gstate.dt = dt;

      for(auto &entite : Entites){
            entite->update();
      }

      this -> instantiate();
}

void Jeu::instantiate(){
}

void Jeu::draw(sf::RenderWindow *window){

      /*
      sf::CircleShape shape(50.f);
      shape.setFillColor(sf::Color::Green);
      window->draw(shape);
      */

      for(auto &entite : Entites){
            entite->draw(window);
      }


}


#include "../Formes/Rectangle.hpp"
#include <iostream>
Jeu::Jeu(){
      this->gstate.time = 0;
      this->gstate.dt = 0;

      int col[] = {255,0,0};
      Entites.push_back(new JoueurPhysique(new Rectangle(100,100,50,50,col)));

      std::cout << "init jeu ok"<< std::endl;
}
