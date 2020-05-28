#ifndef TRAJECTOIRE_HPP
#define TRAJECTOIRE_HPP

class Trajectoire{
public:
      virtual void update(int dt);

      Trajectoire(double _affX, double _affY, double _ampSinX, double _ampSinY, double _freqSinX, double _freqSinY):
      affX(_affX), affY(_affY), ampSinX(_ampSinX), ampSinY(_ampSinY), freqSinX(_freqSinX), freqSinY(_freqSinY), temps(0){};

      double getX(){
            return nextX;
      }

      double getY(){
            return nextY;
      }


private:
      double temps;

      double affX, affY;
      double ampSinX, ampSinY;
      double freqSinX, freqSinY;

      double nextX;
      double nextY;

};

#endif
