#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cmath>
#include "particle.h"

class BHole
{
public:
    sf::RectangleShape rect;

    BHole(sf::Vector2i position)
    {
        rect.setSize(sf::Vector2f(2,2));
        rect.setOrigin( sf::Vector2f(1,1) );
        rect.setFillColor( sf::Color::White );
        rect.setPosition( (sf::Vector2f)position );
    }

    void gravity( std::vector<Particle> &particles )
    {
        sf::Vector2f hol = rect.getPosition();
        for(auto& particle : particles)
        {
            sf::Vector2f par = particle.rect.getPosition();

            float dx = hol.x - par.x;
            float dy = hol.y - par.y;
            float r = sqrt(dx*dx + dy*dy);
            if(r > .1)
            {
                particle.velocity.x += dx/(r*r);
                particle.velocity.y += dy/(r*r);
            }
        }
    }
};
