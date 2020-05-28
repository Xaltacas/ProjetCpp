#include "Jeu.hpp"

void Jeu::step(int dt){
      this -> gstate.dt = dt;
      this -> gstate.time += 0.001*dt;

      for(auto &entite : Entites){
            entite->update(&gstate);
      }

      this -> instantiate();
}

void Jeu::instantiate(){
}

void Jeu::draw(sf::RenderWindow *window){

      for(auto &entite : Entites){
            entite->draw(window);
      }


}


#include "../Formes/Rectangle.hpp"
#include <iostream>
Jeu::Jeu(){
      int col[] = {255,0,0};
      Entites.push_back(new JoueurPhysique(new Rectangle(100,100,50,50,col)));
      this->gstate.entityCount++;

      int col2[] = {255,255,0};
      Entites.push_back(new JoueurPhysique(new Rectangle(200,200,50,50,col2)));
      this->gstate.entityCount++;

      int col3[] = {0,255,0};
      Entites.push_back(new Mechant(new Rectangle(300,300,30,30,col2),new Trajectoire(0,100,1000,0,10,0)));
      this->gstate.entityCount++;

      std::cout << "init jeu ok"<< std::endl;
}
