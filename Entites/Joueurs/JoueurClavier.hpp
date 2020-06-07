#ifndef JOUEURP_HPP
#define JOUEURP_HPP

#include "Joueur.hpp"
#include "../../Trajectoires/Trajectoire.hpp"
#include "../../Formes/Rectangle.hpp"

class JoueurClavier : public Joueur{
public:
      void update(struct Gamestate *gstate);

      JoueurClavier(Forme* f):Joueur(f), shotCooldown(0.1),lastShot(0){};

      ~JoueurClavier(){
            delete forme;
      }

private:
      double shotCooldown;
      double lastShot;
};

#endif
