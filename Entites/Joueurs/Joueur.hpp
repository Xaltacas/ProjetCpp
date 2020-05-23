#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "../Projectiles/Projectile.hpp"
#include "../Entite.hpp"

class Joueur: public Entite {
public:
      Joueur(Forme* f):Entite(f){};


private:
      int vie;
      Projectile projectile();
};

#endif
