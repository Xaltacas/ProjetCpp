#include "Jeu.hpp"
#include <iostream>

void Jeu::step(int dt){
      this -> gstate.dt = dt;
      this -> gstate.time += 0.001*dt;

      for(int i = 0; i < this -> gstate.entityCount;i++){
            for(int j = i+1; j < this -> gstate.entityCount;j++){
                  if(Entites[i] -> collide(Entites[j])){
                        this->gstate.collisionMatrix[i][j] = true;
                        this->gstate.collisionMatrix[j][i] = true;
                        std::cout << "collision   "<< i<<" : "<<j<< std::endl;
                  }
                  else{
                        this->gstate.collisionMatrix[i][j] = false;
                        this->gstate.collisionMatrix[j][i] = false;
                  }
            }

      }



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
#include "../Formes/Cercle.hpp"
#include <string>

Jeu::Jeu(){
      int col[] = {255,0,0};
      Entites.push_back(new JoueurPhysique(new Rectangle(100,100,50,50,col)));
      this->gstate.entityCount++;

      int col2[] = {255,255,0};
      Entites.push_back(new JoueurIA(new Rectangle(100,700,50,50,col2)));
      this->gstate.entityCount++;

      //int col3[] = {0,255,0};
      Entites.push_back(new Mechant(new Forme(300,300,"~Desktop/ProjetCpp/Etats/brique.txt"),new Trajectoire(0,50,200,0,5,0)));
      this->gstate.entityCount++;

      std::cout << "init jeu ok"<< std::endl;
}
