
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <universe.h>

void input();


enum Material{ none, bHole, particle, wHole };

sf::RenderWindow *window;
sf::ContextSettings settings;

Universe g_universe;

Material material = none;

int main()
{
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow( sf::VideoMode(1280, 800, 32),
        "Earth-Editor", sf::Style::Close | sf::Style::Titlebar,
        settings);
    window->setFramerateLimit(60);
    // window->setKeyRepeatEnabled(false);

    while (window->isOpen())
    {
        input();
        window->clear(sf::Color(5, 5, 5));

        g_universe.tick();
        g_universe.draw(window);

        window->display();
    }
    return 0;
}

void input()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window->close();

        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            switch(material)
            {
            case Material(bHole):
                g_universe.add_black_hole(sf::Mouse::getPosition(*window));
                break;

            case Material(particle):
                g_universe.add_particle( sf::Mouse::getPosition(*window) );
                break;

            case Material(wHole):
                g_universe.add_white_hole( sf::Mouse::getPosition(*window) );
                break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            g_universe.clear();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window->close();

        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num0 ) )
            material = none;
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 ) )
            material = particle;
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 ) )
            material = bHole;
        if( sf::Keyboard::isKeyPressed( sf::Keyboard::Num3 ) )
            material = wHole;

    }
}



