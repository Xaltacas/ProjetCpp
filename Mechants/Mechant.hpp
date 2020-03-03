#ifndef MECHANT_HPP
#define MECHANT_HPP

class Mechant{
public:
      virtual void updatePos();
      virtual void ia();

private:
      Trajectoire traj;
      int valeur;
      int vie;
};

#endif
