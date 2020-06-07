#ifndef TRAJECTOIRE_HPP
#define TRAJECTOIRE_HPP


/*
Classe utilisée pour représenter une trajectoire
*/
class Trajectoire{
public:
      //met a jour le prochain déplacement en fontion du temps ecoulé depuis le dernier appel
      void update(int dt);

      Trajectoire(double _affX, double _affY, double _ampSinX, double _ampSinY, double _freqSinX, double _freqSinY,  double _ampCosX, double _ampCosY, double _freqCosX, double _freqCosY):
      temps(0), affX(_affX), affY(_affY), ampSinX(_ampSinX), ampSinY(_ampSinY), freqSinX(_freqSinX), freqSinY(_freqSinY), ampCosX(_ampCosX), ampCosY(_ampCosY), freqCosX(_freqCosX), freqCosY(_freqCosY){};

      double getX(){
            return nextX;
      }

      double getY(){
            return nextY;
      }



private:
      double temps;                 //temps depuis la création de la trajectoire

      double affX, affY;            //Composantes affines de la trajectoire

      //composantes en sinus et cosinus sur chaque axe de la trajectoire
      double ampSinX, ampSinY;
      double freqSinX, freqSinY;
      double ampCosX, ampCosY;
      double freqCosX, freqCosY;

      //déplacement calculé
      double nextX;
      double nextY;

};

#endif
