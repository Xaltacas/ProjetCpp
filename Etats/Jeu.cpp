#include "Jeu.hpp"
#include <iostream>

void Jeu::step(int dt){
      this -> gstate.dt = dt;
      this -> gstate.time += 0.001*dt;

      for(int i = 0; i < this -> gstate.entityCount;i++){
            this -> gstate.entityType[i] = Entites[i] -> getType();
            for(int j = i+1; j < this -> gstate.entityCount;j++){
                  if(Entites[i] -> collide(Entites[j])){
                        this->gstate.collisionMatrix[i][j] = true;
                        this->gstate.collisionMatrix[j][i] = true;
                        std::cout << "collision   "<< i <<"(type = " << this -> gstate.entityType[i] <<" ) : "<<j<< std::endl;
                  }
                  else{
                        this->gstate.collisionMatrix[i][j] = false;
                        this->gstate.collisionMatrix[j][i] = false;
                  }
            }

      }


      this -> gstate.currEntity = 0;

      for(auto &entite : Entites){
            entite->update(&gstate);
            this -> gstate.currEntity++;
      }

      this -> script.update(&gstate);

      this -> instantiate();
}

void Jeu::instantiate(){

      int nbEntite = this->gstate.entityCount;

      for(int i =0; i< nbEntite;i++){
            for(auto &entite : Entites[i]->instanciateList){
                  if(this -> gstate.entityCount < gstate.maxEntity){
                        this -> EntitesTemp.push_back(entite);
                        this -> gstate.entityCount++;
                  }
            }
            Entites[i]->instanciateList.clear();
      }

      for(auto &entite : script.instanciateList){
            if(this -> gstate.entityCount < gstate.maxEntity){
                  this -> EntitesTemp.push_back(entite);
                  this -> gstate.entityCount++;
            }
      }
      script.instanciateList.clear();

      for(auto &entite :this->EntitesTemp){
            this->Entites.push_back(entite);
      }
      this->EntitesTemp.clear();
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
      Entites.push_back(new JoueurPhysique(new Forme(100,100,"/home/roborongeurs/Desktop/ProjetCpp/Formes/Models/J1.txt")));
      this->gstate.entityCount++;

      int col2[] = {255,255,0};
      Entites.push_back(new JoueurIA(new Forme(100,700,"/home/roborongeurs/Desktop/ProjetCpp/Formes/Models/J2.txt")));
      this->gstate.entityCount++;


      int col3[] = {0,255,0};
      Entites.push_back(new Mechant(new Cercle(300,300,20,col3),new Trajectoire(0,50,200,0,5,0)));
      this->gstate.entityCount++;


      std::cout << "init jeu ok"<< std::endl;
}
