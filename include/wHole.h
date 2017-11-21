#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cmath>

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
};
