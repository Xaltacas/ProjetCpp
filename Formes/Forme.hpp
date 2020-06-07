#ifndef FORME_HPP
#define FORME_HPP

#include "Brique.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>


/*
Classe pour représenter une forme.
Chaque forme est composée de 0 à n briques
Une forme peut determiner si elle rentre en collision avec un autre forme.
Une forme peut s'afficher dans une fenètre
*/
class Forme{
public:

      Forme(double _x, double _y,int _nbBriques) : x(_x), y(_y),nbBriques(_nbBriques) {
            briques = new Brique[_nbBriques]();
      };

      //création d'un forme à partir d'un fichier de textures
      //Les fichier de textures représentent un forme au format ascii
      //la première ligne indique le nombre de briques dans la forme puis chaque ligne indique la position, la taille et la couleur de cette brique
      Forme(double _x, double _y, std::string modelpath);


      double getX(){return x;};
      double getY(){return y;};

      //deplace la forme par les valeurs x et y en paramètre
      void move(double x,double y);

      //true si il y a intersection avec la forme f, false sinon
      bool intersect(Forme f);

      //dessine la forme dans la fenètre en paramètre
      void draw(sf::RenderWindow *window);


protected:
      //position de la forme
      double x;
      double y;

      //liste des briques composant la forme
      Brique* briques;
      int nbBriques;

};

#endif
