#ifndef JOUEURP_HPP
#define JOUEURP_HPP

#include "Joueur.hpp"
#include "../../Trajectoires/Trajectoire.hpp"
#include "../../Formes/Rectangle.hpp"

/*
Classe représentant un joueur clavier
*/
class JoueurClavier : public Joueur{
public:
      //methode appellée a chaque itération, gere le comportement du joueur
      void update(struct Gamestate *gstate);

      JoueurClavier(Forme* f):Joueur(f), shotCooldown(0.1),lastShot(0){};

      ~JoueurClavier(){
            delete forme;
      }

private:
      double shotCooldown;    //temps en tre deux tirs
      double lastShot;        //temps du dernier tir
};

#endif
