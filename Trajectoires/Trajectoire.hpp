#ifndef TRAJECTOIRE_HPP
#define TRAJECTOIRE_HPP

class Trajectoire{
public:
      void update(int dt);

      Trajectoire(double _affX, double _affY, double _ampSinX, double _ampSinY, double _freqSinX, double _freqSinY,  double _ampCosX, double _ampCosY, double _freqCosX, double _freqCosY):
      temps(0), affX(_affX), affY(_affY), ampSinX(_ampSinX), ampSinY(_ampSinY), freqSinX(_freqSinX), freqSinY(_freqSinY), ampCosX(_ampCosX), ampCosY(_ampCosY), freqCosX(_freqCosX), freqCosY(_freqCosY){};

      double getX(){
            return nextX;
      }

      double getY(){
            return nextY;
      }

      ~Trajectoire(){}


private:
      double temps;

      double affX, affY;
      double ampSinX, ampSinY;
      double freqSinX, freqSinY;
      double ampCosX, ampCosY;
      double freqCosX, freqCosY;


      double nextX;
      double nextY;

};

#endif
