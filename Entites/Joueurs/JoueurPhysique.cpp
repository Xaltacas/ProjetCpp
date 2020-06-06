#include "JoueurPhysique.hpp"

void JoueurPhysique::update(struct Gamestate *gstate){

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      double deplacement = this -> vitesse * 0.001 * gstate -> dt;



      double movex = 0;
      double movey = 0;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
          movex -= deplacement;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
          movex += deplacement;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
          movey -= deplacement;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
          movey += deplacement;
      }

      if(posx + movex > gstate -> sizeX)
            movex = gstate -> sizeX - posx;
      if(posx + movex < 0)
            movex = - posx;

      if(posy + movey > gstate -> sizeY)
            movey = gstate -> sizeY - posy;
      if(posy + movey < 0)
            movey = - posy;


      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (gstate -> time - this -> lastShot > this -> shotCooldown))
      {
            int col[] = {0,0,255};
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx, posy,"Formes/Models/Pr1.txt"),new Trajectoire(0,-300,0,0,0,0),ENTITE_P_JOUEUR));

      }


      this->forme->move(movex,movey);


      for(int i = 0; i < gstate -> entityCount;i++){
            if(gstate -> collisionMatrix[gstate -> currEntity][i]){
                  if(gstate -> entityType[i] == ENTITE_P_MECHANT){
                        this -> vie--;
                        gstate -> deleteList[i] = true;
                  }

            }
      }

      if(this -> vie <= 0){
            gstate -> deleteList[gstate -> currEntity] = true;
            gstate -> alivePlayer--;
      }
};
