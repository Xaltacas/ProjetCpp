#ifndef ENTITE_HPP
#define ENTITE_HPP

#include "../Formes/Forme.hpp"
#include "../Other/Gamestate.hpp"

#define ENTITE_JOUEUR 1
#define ENTITE_MECHANT 2
#define ENTITE_P_JOUEUR 3
#define ENTITE_P_MECHANT 4





class Entite{
public:

      bool collide(Entite *e){
            return this->forme->intersect(*e->forme);
      }

      void draw(sf::RenderWindow *window){
            this->forme->draw(window);
      }

      virtual void update(struct Gamestate *gstate)=0;

      Entite(Forme* f, int _type){
            this->forme = f;
            this -> type = _type;
      }

      int getType(){
            return this ->type;
      }

      std::vector<Entite*> instanciateList;


protected:
      Forme* forme;

      void Instanciate(Entite *e){
            instanciateList.push_back(e);
      }

      int type;
};

#endif
