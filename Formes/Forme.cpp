#include "Forme.hpp"

void Forme::move(double x,double y){
      this->x += x;
      this->y += y;
}

bool Forme::intersect(Forme f){
      if( !(( f.x + 60 < x )||
            ( f.y + 60 < y )||
            ( x + 60 < f.x )||
            ( y + 60 < f.y )) ){

            for(int i = 0; i < this->nbBriques; i++){
                  for(int j = 0; j < f.nbBriques; j++){
                        if(this->briques[i].intersect(f.briques[j],x,y,f.x,f.y))
                              return true;
                  }
            }
      }

      return false;
}

void Forme::draw(sf::RenderWindow *window){
      for(int i = 0; i < nbBriques; i++){

            briques[i].draw(this->x,this->y,window);
      }
}


 Forme::Forme(double _x, double _y, std::string modelpath) : x(_x), y(_y) {
      std::cout << modelpath << std::endl;
      std::ifstream flux(modelpath.c_str());
      std::cout << "je suis la "<< std::endl;
      if(flux){
            int _nbBriques;
            flux >> _nbBriques;
            this -> nbBriques = _nbBriques;
            std::cout << "nombre de brique :  "<< _nbBriques << std::endl;
            this -> briques = new Brique[_nbBriques]();
            int xb, yb, lengthb, heightb;
            int r,g,b;
            int i = 0;
            while (flux >> xb >> yb >> lengthb >> heightb >> r >> g >> b){
                  int col[] = {r,g,b};
                  this ->briques[i] = Brique(xb ,yb ,lengthb ,heightb, col);
                  i++;
                  //std::cout << "je fais la boucle "<< std::endl;
                  std::cout << "création brique :: " << xb << " " << yb << " " << lengthb << " " << heightb << " " << r << " " << g << " " << b << std::endl;
                  std::cout << i << std::endl;

            }

            std::cout << "j'ai marché "<< std::endl;

      }else{
            std::cout << "erreur chargement "<< std::endl;
      }
}
