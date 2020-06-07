
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Formes/Forme.hpp"


/*
Main utilisé pour tester les textures
*/

int main(){
      sf::RenderWindow window(sf::VideoMode(300,300), "test Texture");
      sf::RectangleShape rect(sf::Vector2f(300,300));
      rect.setPosition(0, 0);
      rect.setFillColor(sf::Color(127,127,127));


      Forme j1 = Forme(50,50,"Formes/Models/J1.txt");
      Forme j2 = Forme(250,50,"Formes/Models/J2.txt");

      Forme m1 = Forme(50,100,"Formes/Models/M1.txt");
      Forme m2 = Forme(150,100,"Formes/Models/M2.txt");
      Forme m3 = Forme(250,100,"Formes/Models/M3.txt");
      Forme m4 = Forme(150,50,"Formes/Models/M4.txt");


      Forme pr1 = Forme(70,170,"Formes/Models/Pr1.txt");
      Forme pr2 = Forme(150,170,"Formes/Models/Pr2.txt");
      Forme pr3 = Forme(230,170,"Formes/Models/Pr3.txt");

      Forme pr4 = Forme(70,250,"Formes/Models/Pr4.txt");
      Forme pr5 = Forme(150,250,"Formes/Models/Pr5.txt");
      Forme pr6 = Forme(230,250,"Formes/Models/Pr6.txt");



      while (window.isOpen())
      {

            window.clear();
            window.draw(rect);

            j1.draw(&window);
            j2.draw(&window);

            m1.draw(&window);
            m2.draw(&window);
            m3.draw(&window);
            m4.draw(&window);

            pr1.draw(&window);
            pr2.draw(&window);
            pr3.draw(&window);

            pr4.draw(&window);
            pr5.draw(&window);
            pr6.draw(&window);

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
