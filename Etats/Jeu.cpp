#include "Jeu.hpp"
#include <iostream>

void Jeu::step(int dt){
      this -> gstate.dt = dt;
      this -> gstate.time += 0.001*dt;

      for(int i = 0; i < MAX_ENTITY; i++){
            gstate.deleteList[i] = false;
            gstate.entityType[i] = 0;
            for(int j =0; j < MAX_ENTITY; j++)
                  gstate.collisionMatrix[i][j] = false;
      }

      for(int i = 0; i < this -> gstate.entityCount;i++){
            this -> gstate.entityType[i] = Entites[i] -> getType();
            for(int j = i+1; j < this -> gstate.entityCount;j++){
                  if(Entites[i] -> collide(Entites[j])){
                        this->gstate.collisionMatrix[i][j] = true;
                        this->gstate.collisionMatrix[j][i] = true;
                        //std::cout << "collision   "<< i <<"(type = " << this -> gstate.entityType[i] <<" ) : "<<j<< std::endl;
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

      int nbEntity = this -> gstate.entityCount;

      for(int i = nbEntity - 1; i>=0;i--){
            if(this -> gstate.deleteList[i]){
                  //std::cout << "vector size : "<< Entites.size() <<  std::endl;
                  //std::cout << "erased entity : "<< i <<  std::endl;
                  //std::cout << "vector size : "<< Entites.size() <<  std::endl;
                  Entite *temp = Entites[i];

                  Entites.erase(Entites.begin() + i);
                  this -> gstate.entityCount--;

                  delete temp;
            }
      }
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


      scoreText.setString("score : " +std::to_string(this -> gstate.score) +"\nPV j1 : "+std::to_string(this -> gstate.pvJ1));
      window -> draw(scoreText);

      if(this -> gstate.alivePlayer == 0){
            window -> draw(perdu);
      }

}

#include <string>

Jeu::Jeu(){

      Entites.push_back(new JoueurClavier(new Forme(300,700,"Formes/Models/J1.txt")));
      this->gstate.entityCount++;
      this->gstate.alivePlayer++;



      Entites.push_back(new JoueurIA(new Forme(100,700,"Formes/Models/J2.txt")));
      this->gstate.entityCount++;
      this->gstate.alivePlayer++;


      if (!font.loadFromFile("Roboto-Black.ttf"))
      {
          std::cout << "erreur chargement font" <<  std::endl;
      }
      scoreText.setFont(font);
      scoreText.setCharacterSize(24);
      scoreText.setFillColor(sf::Color::White);

      perdu.setFont(font);
      perdu.setCharacterSize(70);
      perdu.setString("Perdu");
      perdu.setPosition({200,400});
      perdu.setFillColor(sf::Color::Red);

      std::cout << "init jeu ok"<< std::endl;
}
