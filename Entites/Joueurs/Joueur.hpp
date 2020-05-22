#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "../Projectiles/Projectile.hpp"
#include "../Entite.hpp"

class Joueur: public Entite {

private:
      int vie;
      Projectile projectile;
};

#endif
