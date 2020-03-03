#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Joueur{
public:
      virtual void updatePos();
      virtual void actions();

private:
      int vie;
      int id;
};

#endif
