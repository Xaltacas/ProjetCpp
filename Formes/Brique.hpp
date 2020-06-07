#ifndef BRIQUE_HPP
#define BRIQUE_HPP

#include <SFML/Graphics.hpp>


/*
classe pour représenter une brique.
La brique est l'element de base de notre moteur graphique, c'est un rectangle monochrome, une sorte de pixel de taille variable
l'affichage dans la fenètre et les calculs de collision se font réelement au niveau de la brique
*/
class Brique{
public:
      //renvoie vrai si il y a intersection avec la brique B
      //x1,y1 et x2,y2 etant respectivement les coordonnés de la forme à laquelle appartiennent les briques.
      bool intersect(Brique b, int _x1, int _y1, int _x2 ,int _y2);

      //dessine la brique dans la fenètre en paramètre
      //x et y sont les coordonnés de la forme a laquelle la brique appartient
      void draw(double x,double y,sf::RenderWindow *window);

      Brique(double _x, double _y, double _length, double _height,int* _color) :
            x(_x),y(_y),length(_length),height(_height) {
                  color[0] = _color[0];
                  color[1] = _color[1];
                  color[2] = _color[2];
      }

      Brique(){
            x = 0;
            y = 0;
            length = 0;
            height = 0;

      }

private:
      //position de la brique dans la forme a laquelle elle appartient
      double x;
      double y;

      //dimentions de la brique
      double length;
      double height;

      //couleur de la brique
      int color[3];

};

#endif
