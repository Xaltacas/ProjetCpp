#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Etats/Jeu.hpp"
//#include "Formes/Forme.hpp"



int main(){

      std::cout << "ca complie!! incroyable!!"<< std::endl;
      sf::RenderWindow window(sf::VideoMode(600, 900), "Hacode");

      sf::Texture texture;
      if (!texture.loadFromFile("background.png"))
      {
            std::cout <<"Impossible to load background"<< std::endl;
      }

      sf::Sprite sprite;
      sprite.setTexture(texture);


      unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned long int before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned int dt;

      Jeu jeu = Jeu();
      sf::Music music;
      if (!music.openFromFile("Music/music1.flac"))
            std::cout <<"Impossible to load music"<< std::endl;
      music.play();
      //music.setVolume(100);
      //music.setLoop(true);

      while (window.isOpen())
      {
            while (now - before < 20){
                  now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            }
            dt = now-before;
            before = now;
            std::cout << "fps = " << 1000/dt << std::endl;
            window.clear();
            //window.setSize({600,900});
            //std::cout << "cc0"<< std::endl;
            window.draw(sprite);
            //std::cout << "cc1"<< std::endl;
            jeu.step(dt);
            //std::cout << "cc2"<< std::endl;
            jeu.draw(&window);
            //std::cout << "cc3"<< std::endl;
            window.display();


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
