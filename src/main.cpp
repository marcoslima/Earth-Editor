
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include <wHole.h>

void input();


enum Material{ none, bHole, particle, wHole };

sf::RenderWindow *window;
sf::ContextSettings settings;

std::vector<Particle> particles;
std::vector<BHole> bHoles;
std::vector<WHole> wHoles;


Material material = none;

int main()
{
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow( sf::VideoMode(1280, 800, 32),
        "Earth-Editor", sf::Style::Close | sf::Style::Titlebar,
        settings);  // sf::Style::Close | sf::Style::Titlebar
    window->setFramerateLimit(60);
    // window->setKeyRepeatEnabled(false);

    while (window->isOpen())
    {
        input();
        window->clear(sf::Color(5, 5, 5));

        int value = bHoles.size();
        for(int i = 0; i<value; i++)
        {
            bHoles[i].gravity(particles);
            window->draw(bHoles[i].rect);
        }

        value = wHoles.size();
        for(int i = 0; i<value; i++)
        {
            wHoles[i].gravity(particles);
            window->draw(wHoles[i].m_rect);
        }

        value = particles.size();
        for(int i = 0; i<value; i++)
        {
            particles[i].move();
            window->draw(particles[i].rect);
        }



        window->display();
    }
    return 0;
}

//12312312312312
//121231231231231
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
                {
                    BHole bHole( sf::Mouse::getPosition(*window) );
                    bHoles.push_back(bHole);
                    break;
                }

                case Material(particle):
                {
                    Particle particle( sf::Mouse::getPosition(*window) );
                    particles.push_back(particle);
                    break;
                }

                case Material(wHole):
                {
                    WHole wHole( sf::Mouse::getPosition(*window) );
                    wHoles.push_back(wHole);
                    break;
                }

                case Material(none):
                    break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            bHoles.clear();
            particles.clear();
            wHoles.clear();
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



