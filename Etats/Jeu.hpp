#ifndef JEU_HPP
#define JEU_HPP

#include <vector>
#include "Etat.hpp"7
#include "../Joueurs/Joueur.hpp"
#include "../Mechants/Mechant.hpp"

class Jeu : public Etat{
public:
      void step();
      void draw();
      //void instantiateProjectile(Projectile p);

private:
      int score;
      Joueur joueurs[2];
      std::vector<Mechant> Mechants;
      //std::vector<Projectile> Projectiles;
};

#endif
