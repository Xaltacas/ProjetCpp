#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "../Entite.hpp"
#include "../Projectiles/Projectile.hpp"

/*
Classe abstraite pour representer un joueur
*/
class Joueur: public Entite {
public:
Joueur(Forme* f):Entite(f,ENTITE_JOUEUR),vitesse(400),vie(5){};

protected:
      int vitesse; //vitesse en pixels par seconde;
      int vie; //nombre de coup que peut subir le joueur;
};

#endif
