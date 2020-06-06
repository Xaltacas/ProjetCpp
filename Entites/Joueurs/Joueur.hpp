#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "../Projectiles/Projectile.hpp"
#include "../Entite.hpp"

class Joueur: public Entite {
public:
Joueur(Forme* f):Entite(f,ENTITE_JOUEUR),vitesse(400){};

protected:
      int vitesse; //vitesse en pixels par seconde;
      int vie;
};

#endif
