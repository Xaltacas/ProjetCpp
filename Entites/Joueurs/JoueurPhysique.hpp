#ifndef JOUEURP_HPP
#define JOUEURP_HPP

#include "Joueur.hpp"
#include "../../Trajectoires/Trajectoire.hpp"
#include "../../Formes/Rectangle.hpp"

class JoueurPhysique : public Joueur{
public:
      void update(struct Gamestate *gstate);

      JoueurPhysique(Forme* f):Joueur(f), shotCooldown(0.1),lastShot(0){};

private:
      double shotCooldown;
      double lastShot;
};

#endif
