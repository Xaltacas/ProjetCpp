#ifndef JOUEURP_HPP
#define JOUEURP_HPP

#include "Joueur.hpp"
#include "../../Formes/Rectangle.hpp"

class JoueurPhysique : public Joueur{
public:
      void update(struct Gamestate *gstate);

      JoueurPhysique(Forme* f):Joueur(f), shotCooldown(0.4),lastShot(0){};

private:
      double shotCooldown;
      double lastShot;
};

#endif
