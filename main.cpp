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


      unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned long int before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned int dt;

      dPrint("pre init");
      Jeu jeu = Jeu();
      dPrint("post init");

      while (window.isOpen())
      {
            while (now - before < 20){
                  now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            }
            dt = now-before;
            before = now;
            std::cout << "fps = " << 1000/dt << std::endl;
            dPrint("pre display");
            window.clear();
            window.setSize({600,900});
            window.draw(sprite);
            jeu.step(dt);
            jeu.draw(&window);
            window.display();
            dPrint("post display");


            sf::Event event;
            while (window.pollEvent(event))
            {
                  if (event.type == sf::Event::Closed)
                  window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                  std::cout << "the escape key was pressed" << std::endl;
                  window.close();
            }
      }


      return 0;
}
