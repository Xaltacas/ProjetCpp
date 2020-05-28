#ifndef ENTITE_HPP
#define ENTITE_HPP

#include "../Formes/Forme.hpp"
#include "../Other/Gamestate.hpp"

class Entite{
public:

      bool Collide(Entite *e){
            return this->forme->intersect(*e->forme);
      }

      void draw(sf::RenderWindow *window){
            this->forme->draw(window);
      }

      virtual void update(struct Gamestate *gstate)=0;

      Entite(Forme* f){
            this->forme = f;
      }

      std::vector<Entite*> instanciateList;


protected:
      Forme* forme;

      void Instanciate(Entite *e){
            instanciateList.push_back(e);
      }
};

#endif
