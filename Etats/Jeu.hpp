#ifndef JEU_HPP
#define JEU_HPP
#include "Etat.hpp"

class Jeu : public Etat{
public:
      void step();
      void draw();
      void instantiateProjectile(Projectile p);

private:
      int score;
      Joueur[2] joueurs;
      std::vector<Mechant> Mechants;
      std::vector<Projectile> Projectiles;
};

#endif
