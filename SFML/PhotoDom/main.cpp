// код выполняет:
// SFML программа игра

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
/* #include <SFML/Graphics/sprite.hpp> */
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
namespace rr{
    sf::RenderWindow window (sf::VideoMode(600, 500), "SFML works!");
};


int main ()
{
    sf::Sprite  sprite;
    sf::Texture myPhoto;
                 myPhoto.loadFromFile ("./image.jpg");


    sf::IntRect kvadrat (150,150,350,250);  // расположение фото внутри квадрата
                                            //

    sprite.setTexture     ( myPhoto ) ;
    sprite.setTextureRect ( kvadrat ) ;
    sprite.setPosition    ( 160,50   ) ;     // расположение квадрата с фото


    sf::IntRect newSize (0,0, 120,100);
    sprite.setTextureRect (newSize);



    /* sprite.setScale       (2.5, 2.5);        // размер самого сплайна но не текстуры */
    /* myPhoto.loadFromImage(2.5, 2.5); */

    while (rr::window.isOpen())
    {
        sf::Event event;
        while (rr::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                rr::window.close();
        }


/* sf::Vector2f targetSize(600.0f, 500.0f); //целевой размер */
 
/* sprite.setScale( */
/*     targetSize.x / sprite.getLocalBounds().width, */ 
/*     targetSize.y / sprite.getLocalBounds().height); */


        rr::window.clear   ( );
        rr::window.draw    (sprite);
        rr::window.display ( );

    }//while

    return 0;
 } 

