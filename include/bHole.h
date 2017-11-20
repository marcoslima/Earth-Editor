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
        int vecSize = particles.size();
        for(int i = 0; i < vecSize; i++ )
        {
            sf::Vector2f par = particles[i].rect.getPosition();
            sf::Vector2f hol = rect.getPosition();

            float a = std::max( par.x, hol.x ) - std::min( par.x, hol.x );
            float b = std::max( par.y, hol.y ) - std::min( par.y, hol.y );
            float c = std::sqrt(a*a + b*b);
            float dx, dy;

            if(a>b)
            {
                dx = 1;
                dy = b/a;
            }

            else if(b>a)
            {
                dy = 1;
                dx = a/b;
            }

            if (a < 1)
                dx = 0;
            if (b < 1)
                dy = 0;
            a = hol.x - par.x;
            b = hol.y - par.y;
            if (a < 0)
                dx = -dx;
            if (b < 0)
                dy = -dy;

            particles[i].velocity.x += dx/c;
            particles[i].velocity.y += dy/c;

        }
    }
};
