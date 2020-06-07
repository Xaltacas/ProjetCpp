#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Formes/Forme.hpp"
#include "Formes/Brique.hpp"

//Ce fichier sert a faire les tests unitaires des formes et des briques dans leurs collisions
//Test des collisions des formes avec un cas aui touche completement, un cas qui
// touche a un pixel, un cas ou les formes sont colées et un cas ou ca ne touche pas

//Une fenetre permet de visualiser les cas
TEST_CASE ( "test collisions formes", "[Test collisions formes]"){

      sf::RenderWindow window(sf::VideoMode(100,100), "test Texture");
      sf::RectangleShape rect(sf::Vector2f(100,100));
      rect.setPosition(0, 0);
      rect.setFillColor(sf::Color(127,127,127));

      Forme m1 = Forme(30,30,"Formes/Models/M2.txt");
      Forme m2 = Forme(50,30,"Formes/Models/M2.txt");
      Forme m3 = Forme(30,54,"Formes/Models/M2.txt");
      Forme m4 = Forme(60,54,"Formes/Models/M2.txt");



      while (window.isOpen())
      {

            window.clear();
            window.draw(rect);

            m1.draw(&window);
            m2.draw(&window);
            m3.draw(&window);
            m4.draw(&window);


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

      REQUIRE( m1.intersect(m2));
      REQUIRE( m1.intersect(m3));
      REQUIRE( !m3.intersect(m4));
      REQUIRE( !m2.intersect(m4));
}


//Test des collisions des briques avec un cas aui touche completement, un cas qui
// touche a un pixel, un cas ou les formes sont colées et un cas ou ca ne touche pas

//Une fenetre permet de visualiser les cas, mais attention elle est tres petite
//Il vaut faut l'augmenter pour pouvoir bien observer les cas
TEST_CASE ( "test collisions briques", "[Test collisions briques]"){

      sf::RenderWindow window(sf::VideoMode(10,10), "test Texture");
      sf::RectangleShape rect(sf::Vector2f(10,10));
      rect.setPosition(0, 0);
      rect.setFillColor(sf::Color(127,127,127));

      int rouge[] = {255,0,0};
      int vert[] = {0,255,0};
      int bleu[] = {0,0,255};
      int jaune[] = {255,255,0};


      Brique b1 = Brique(0,0,4,4,rouge);
      Brique b2 = Brique(0,4,4,4,vert);
      Brique b3 = Brique(2,0,4,4,bleu);
      Brique b4 = Brique(5,3,4,4,jaune);





      while (window.isOpen())
      {

            window.clear();
            window.draw(rect);

            b1.draw(0,0,&window);
            b2.draw(0,0,&window);
            b3.draw(0,0,&window);
            b4.draw(0,0,&window);


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

      REQUIRE( !b1.intersect(b2,0,0,0,0));
      REQUIRE( b1.intersect(b3,0,0,0,0));
      REQUIRE( b3.intersect(b4,0,0,0,0));
      REQUIRE( !b2.intersect(b4,0,0,0,0));


}
