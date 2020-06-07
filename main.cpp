#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Etats/Jeu.hpp"


int main(){

      std::cout << "Lancement du Jeu"<< std::endl;

      //création de la fenètre de jeu
      sf::RenderWindow window(sf::VideoMode(600, 900), "Hacode");

      //chargement du fond
      sf::Texture texture;
      if (!texture.loadFromFile("background.png"))
      {
            std::cout <<"Impossible to load background"<< std::endl;
      }
      sf::Sprite sprite;
      sprite.setTexture(texture);

      //initialisation du temps
      unsigned long int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned long int before = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
      unsigned int dt;

      //chargement de la musique
      sf::Music music;
      if (!music.openFromFile("Music/music1.flac"))
            std::cout <<"Impossible to load music"<< std::endl;
      music.play();



      Jeu jeu = Jeu();

      while (window.isOpen())
      {
            //limitaion des fps à 50
            while (now - before < 20){
                  now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            }
            dt = now-before;
            before = now;
            std::cout << "fps = " << 1000/dt << std::endl;

            window.clear();         //on vide la fenètre
            window.draw(sprite);    //on dessine le fond
            jeu.step(dt);           //on avance le jeu
            jeu.draw(&window);      //on dessine le jeu
            window.display();       //on affiche la fenètre

            //verification si l'on ferme le jeu
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
