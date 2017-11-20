#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Particle
{
public:
    sf::Vector2f velocity;
    sf::RectangleShape rect;

    Particle(sf::Vector2i position)
    {
        rect.setSize(sf::Vector2f(2,2));
        rect.setOrigin( sf::Vector2f(1,1) );
        rect.setFillColor( sf::Color::Green );
        rect.setPosition( (sf::Vector2f)position );
        velocity = sf::Vector2f(rand() % 5 - 2, rand() % 5 - 2);
    }

    void move()
    {
        rect.move(velocity);
    }
};
