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
        int vecSize = particles.size();
        sf::Vector2f hol = m_rect.getPosition();
        for (auto& particle : particles)
        {
            sf::Vector2f par = particle.rect.getPosition();

            float a = abs( par.x - hol.x );
            float b = abs( par.y - hol.y );
            float c = std::sqrt(a * a + b * b);
            float dx, dy;

            if (a > b && b)
            {
                dx = 1;
                dy = b / a;
            }

            else if (b > a && a)
            {
                dy = 1;
                dx = a / b;
            }

            /* if (a < 1)
                 dx = 0;
             if (b < 1)
                 dy = 0; */
            a = hol.x - par.x;
            b = hol.y - par.y;
            if (a < 0)
                dx = -dx;
            if (b < 0)
                dy = -dy;

            particle.velocity.x -= dx / c;
            particle.velocity.y -= dy / c;

        }
    }
};
