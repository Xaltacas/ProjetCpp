#ifndef ENTITE_HPP
#define ENTITE_HPP

#include "../Formes/Forme.hpp"

class Entite{
public:

      bool Collide(Entite *e){
            return this->forme->intersect(*e->forme);
      }

      void draw(sf::RenderWindow *window){
            this->forme->draw(window);
      }

      virtual void update()=0;

      Entite(Forme* f){
            this->forme = f;
      }

protected:
      Forme* forme;
      std::vector<Entite*> instanciateList;

      void Instanciate(Entite *e){
            instanciateList.push_back(e);
      }
};

#endif
