#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Etats/Jeu.hpp"
#include "Formes/Forme.hpp"

//#define DEBUG
#include "debugPrint.hpp"


int main(){

      std::cout << "ca complie!! incroyable!!"<< std::endl;
      sf::RenderWindow window(sf::VideoMode(600, 900), "Hacode");

      sf::Texture texture;
      if (!texture.loadFromFile("background.png"))
      {
          dPrint("Impossible to load background");
      }

      sf::Sprite sprite;
      sprite.setTexture(texture);


      unsigned long int now;
      unsigned long int before;
      now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

      dPrint("pre init");
      Jeu jeu = Jeu();
      dPrint("post init");

      while (window.isOpen())
      {
          dPrint("post init 2");
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window.close();
          }
          dPrint("post init 3");

          dPrint("pre display");
          window.clear();
          window.draw(sprite);
          jeu.step();
          jeu.instantiate();
          jeu.draw(&window);
          window.display();
          dPrint("post display");

          while (now - before < 10){
                now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
          }
          std::cout << "fps = " << 1000/(now-before) << std::endl;
          before = now;

      }


      return 0;
}
