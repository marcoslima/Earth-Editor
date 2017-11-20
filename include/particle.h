#pragma once

#include <SFML/Graphics.hpp>

class Particle
{
public:
    sf::Vector2f velocity;
    sf::RectangleShape rect;

    Particle(sf::Vector2i position)
    {
        rect.setSize(sf::Vector2f(2,2));
        rect.setOrigin( sf::Vector2f(1,1) );
        rect.setFillColor( sf::Color::Red );
        rect.setPosition( (sf::Vector2f)position );
        velocity = sf::Vector2f(0,0);
    }

    void move()
    {
        rect.move(velocity);
    }
};
