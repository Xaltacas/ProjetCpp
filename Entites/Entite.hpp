#ifndef ENTITE_HPP
#define ENTITE_HPP

#include "../Formes/Forme.hpp"
#include "../Other/Gamestate.hpp"

#define ENTITE_JOUEUR 1
#define ENTITE_MECHANT 2
#define ENTITE_P_JOUEUR 3
#define ENTITE_P_MECHANT 4


/*
Classe de base pour représenter une entité.
Chaque entité a une forme qui permet l'affichage et le calcul des collisions.
Chaque entité est identifiée par un type (joueur,méchant,projectile).
*/
class Entite{
public:

      //renvoie true si il y a collision avec l'entité e, false sinon
      bool collide(Entite *e){
            return this->forme->intersect(*e->forme);
      }

      //dessine l'entité dans la fenetre en paramètre
      void draw(sf::RenderWindow *window){
            this->forme->draw(window);
      }

      //fonction appellée pour mettre a jour l'entité
      //gère le déplacement, comportement...
      virtual void update(struct Gamestate *gstate)=0;


      Entite(Forme* f, int _type){
            this->forme = f;
            this -> type = _type;
      }

      //renvoie le type de l'entité
      int getType(){
            return this ->type;
      }

      //liste d'entité que cette entité souhaite instancier dans le jeu
      std::vector<Entite*> instanciateList;


protected:
      //forme (et texture) de l'entité
      Forme* forme;

      //type de l'entité
      int type;
};

#endif
