#ifndef JOUEUR_HPP
#define JOUEUR_HPP


#include "../Entite.hpp"
#include "../Projectiles/Projectile.hpp"

class Joueur: public Entite {
public:
Joueur(Forme* f):Entite(f,ENTITE_JOUEUR),vitesse(400),vie(3){};

protected:
      int vitesse; //vitesse en pixels par seconde;
      int vie;
};

#endif
