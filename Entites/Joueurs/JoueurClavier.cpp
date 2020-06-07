#include "JoueurClavier.hpp"

void JoueurClavier::update(struct Gamestate *gstate){

      double posx = this->forme->getX();
      double posy = this->forme->getY();

      double deplacement = this -> vitesse * 0.001 * gstate -> dt;

      //recupération des imputs pour le mouvement
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

      //limitation des mouvement pour ne pas sortir du cadre
      if(posx + movex > gstate -> sizeX)
            movex = gstate -> sizeX - posx;
      if(posx + movex < 0)
            movex = - posx;

      if(posy + movey > gstate -> sizeY)
            movey = gstate -> sizeY - posy;
      if(posy + movey < 0)
            movey = - posy;

      this->forme->move(movex,movey);

      //recuperation et test pour tirer des projectiles
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (gstate -> time - this -> lastShot > this -> shotCooldown))
      {
            this -> lastShot = gstate -> time;
            this -> instanciateList.push_back(new Projectile(new Forme(posx+10, posy -5,"Formes/Models/Pr1.txt"),new Trajectoire(0,-1000,0,0,0,0,0,0,0,0),ENTITE_P_JOUEUR));
            this -> instanciateList.push_back(new Projectile(new Forme(posx-10, posy -5,"Formes/Models/Pr1.txt"),new Trajectoire(0,-1000,0,0,0,0,0,0,0,0),ENTITE_P_JOUEUR));
      }



      //test face aux autres entités pour les degats subis
      for(int i = 0; i < gstate -> entityCount;i++){
            if(gstate -> collisionMatrix[gstate -> currEntity][i]){
                  if(gstate -> entityType[i] == ENTITE_P_MECHANT){
                        this -> vie--;
                        gstate -> deleteList[i] = true;
                  }

            }
      }

      //tests sur les pv pur savoir quand se supprimer
      if(this -> vie <= 0){
            gstate -> deleteList[gstate -> currEntity] = true;
            gstate -> alivePlayer--;
      }

      //indication des pvs au gamestate
      gstate -> pvJ1 = this -> vie;
};
