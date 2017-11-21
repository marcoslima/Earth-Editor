#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cmath>

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
};
