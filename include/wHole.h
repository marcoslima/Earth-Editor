#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cmath>
#include "bHole.h"

class WHole
{
public:
    sf::RectangleShape m_rect;

    WHole(sf::Vector2i position)
    {
        m_rect.setSize(sf::Vector2f(2, 2));
        m_rect.setOrigin( sf::Vector2f(1, 1) );
        m_rect.setFillColor( sf::Color::White );
        m_rect.setPosition( (sf::Vector2f)position );
    }

    void gravity( std::vector<Particle> &particles )
    {
        sf::Vector2f hol = m_rect.getPosition();
        for (auto& particle : particles)
        {
            sf::Vector2f par = particle.rect.getPosition();

            float dx = hol.x - par.x;
            float dy = hol.y - par.y;
            float r = sqrt(dx*dx + dy*dy);
            if(r > .1)
            {
                particle.velocity.x -= dx/(r*r);
                particle.velocity.y -= dy/(r*r);
            }
        }
    }
};
