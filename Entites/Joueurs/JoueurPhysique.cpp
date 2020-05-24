#include "JoueurPhysique.hpp"

//#include "../../debugPrint.hpp"

void JoueurPhysique::update(){
      //dPrint("JP.update");
      double movex = 0;
      double movey = 0;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
          movex -= 10;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
          movex += 10;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
          movey -= 10;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
          movey += 10;
      }

      this->forme->move(movex,movey);
};
