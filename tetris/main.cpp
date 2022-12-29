// код выполняет:
// игра тетрис

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <time.h>
#include <iostream>
using namespace std;

int main ()
{
    sf::RenderWindow window(sf::VideoMode (320,480), "game");

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display ();
    }

}

