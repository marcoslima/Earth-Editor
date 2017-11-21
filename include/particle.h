#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Particle
{
public:
    sf::Vector2f velocity;
    sf::RectangleShape rect;

    Particle(sf::Vector2i position, sf::Vector2f vel = sf::Vector2f(0,0))
    {
        rect.setSize(sf::Vector2f(2,2));
        rect.setOrigin( sf::Vector2f(1,1) );
        rect.setFillColor( sf::Color::Green );
        rect.setPosition( (sf::Vector2f)position );
        velocity = vel;
    }

    void move()
    {
        rect.move(velocity);
    }
};
