#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Etats/Jeu.hpp"
#include "Formes/Forme.hpp"


int main(){

      std::cout << "ca complie!! incroyable!!"<< std::endl;
      sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

      unsigned long int now;
      unsigned long int before;
      now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();


      Jeu jeu = Jeu();

      while (window.isOpen())
      {
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window.close();
          }

          window.clear();
          jeu.step();
          jeu.instantiate();
          jeu.draw(&window);
          window.display();

          while (now - before < 10){
                now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
          }

          std::cout << now << std::endl;
          std::cout << "fps = " << 1000/(now-before) << std::endl;
          before = now;

      }


      return 0;
}
