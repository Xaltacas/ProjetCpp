#include "Jeu.hpp"
#include <iostream>


//fait tous les calculs sur l'interval de temps dt en paramètre
void Jeu::step(int dt){
      //mis a jours des paramètres de temps dans le gamestate
      this -> gstate.dt = dt;
      this -> gstate.time += 0.001*dt;

      //netoyage des anciennes valeurs dans le gamestate
      for(int i = 0; i < MAX_ENTITY; i++){
            gstate.deleteList[i] = false;
            gstate.entityType[i] = 0;
            for(int j =0; j < MAX_ENTITY; j++)
                  gstate.collisionMatrix[i][j] = false;
      }

      //calcul des cllsions entre chaques entités et mise a jours de la liste des types d'entités
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

      //update chaque entité
      this -> gstate.currEntity = 0;
      for(auto &entite : Entites){
            entite->update(&gstate);
            this -> gstate.currEntity++;
      }

      //update du script
      this -> script.update(&gstate);

      //instanciation des nouvelles entités
      this -> instantiate();

      //suppressions des entités qui doivent l'etre.
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

      //instanciation des entité crée par d'autres entités dans une liste temporaire
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

      //instanciation des entitées crées par le script dans une liste temporaire
      for(auto &entite : script.instanciateList){
            if(this -> gstate.entityCount < gstate.maxEntity){
                  this -> EntitesTemp.push_back(entite);
                  this -> gstate.entityCount++;
            }
      }
      script.instanciateList.clear();

      //intanciation des entités dans la liste réelle
      for(auto &entite :this->EntitesTemp){
            this->Entites.push_back(entite);
      }
      this->EntitesTemp.clear();
}

void Jeu::draw(sf::RenderWindow *window){

      //dessine chaque entités
      for(auto &entite : Entites){
            entite->draw(window);
      }

      //dessine le score et la vie du joueur 1
      scoreText.setString("score : " +std::to_string(this -> gstate.score) +"\nPV j1 : "+std::to_string(this -> gstate.pvJ1));
      window -> draw(scoreText);

      //check si les joueurs ont perdu
      if(this -> gstate.alivePlayer == 0){
            window -> draw(perdu);
      }

}


Jeu::Jeu(){

      //création des deux joueurs
      Entites.push_back(new JoueurClavier(new Forme(300,700,"Formes/Models/J1.txt")));
      this->gstate.entityCount++;
      this->gstate.alivePlayer++;

      Entites.push_back(new JoueurIA(new Forme(100,700,"Formes/Models/J2.txt")));
      this->gstate.entityCount++;
      this->gstate.alivePlayer++;

      //chargement des textes
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
