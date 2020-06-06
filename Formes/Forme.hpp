#ifndef FORME_HPP
#define FORME_HPP

#include "Brique.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Forme{
public:

      Forme(double _x, double _y,int _nbBriques) : x(_x), y(_y),nbBriques(_nbBriques) {
            briques = new Brique[_nbBriques]();
      };

      Forme(double _x, double _y, std::string modelpath) : x(_x), y(_y) {
            std::cout << modelpath << std::endl;
            std::ifstream flux(modelpath.c_str());
            std::cout << "je suis la "<< std::endl;
            if(flux){
                  int _nbBriques = 0;
                  flux >> _nbBriques;
                  std::cout << "nombre de brique :  "<< _nbBriques << std::endl;
                  briques = new Brique[_nbBriques]();
                  int xb, yb, lengthb, heightb;
                  int r,g,b;
                  int i = 0;
                  while (flux >> xb >> yb >> lengthb >> heightb >> r >> g >> b){
                        int col[] = {r,g,b};
                        briques[i] = Brique(xb ,yb ,lengthb ,heightb, col);
                        i++;
                        std::cout << "je fais la boucle "<< std::endl;
                        std::cout << xb << " " << yb << " " << lengthb << " " << heightb << " " << r << " " << g << " " << b << std::endl;
                  }

                  std::cout << "j'ai marché "<< std::endl;

            }else{
                  std::cout << "erreur chargement "<< std::endl;
            }
      };

      /*
      ~Forme(){
            delete(briques);
      }
      */

      double getX(){return x;};
      double getY(){return y;};

      void move(double x,double y);

      bool intersect(Forme f);

      void draw(sf::RenderWindow *window);


protected:
      double x;
      double y;

      Brique* briques;
      int nbBriques;

};

#endif
