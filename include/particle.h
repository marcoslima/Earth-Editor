#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <bHole.h>
#include <wHole.h>

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

    sf::Vector2f calc_accel(sf::Vector2f hole)
    {
        sf::Vector2f pos = rect.getPosition();
        sf::Vector2f delta = hole - pos;
        float r = sqrt(delta.x * delta.x + delta.y * delta.y);
        if(r > .05)
        {
            return delta / (r*r);
        }
        else
        {
            return sf::Vector2f(0, 0);
        }
    }

    void apply_bHole(const BHole& bhole)
    {
        velocity += calc_accel(bhole.rect.getPosition());
    }

    void apply_wHole(const WHole& whole)
    {
        velocity -= calc_accel(whole.m_rect.getPosition());
    }

    void move()
    {
        rect.move(velocity);
    }
};
