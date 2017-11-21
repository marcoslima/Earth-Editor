#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <bHole.h>
#include <wHole.h>
#include <particle.h>

class Universe
{
private:
    std::vector<Particle> _particles;
    std::vector<BHole> _black_holes;
    std::vector<WHole> _white_holes;

public:
    Universe()
    {
    }

    void tick(void)
    {
        for(auto& part : _particles)
        {
            for(const auto& bhole : _black_holes)
            {
                part.apply_bHole(bhole);
            }
            for(const auto& whole : _white_holes)
            {
                part.apply_wHole(whole);
            }
            part.move();
        }
    }

    void draw(sf::RenderWindow* window)
    {
        for(auto& bhole : _black_holes)
        {
            window->draw(bhole.rect);
        }

        for(auto& whole : _white_holes)
        {
            window->draw(whole.m_rect);
        }

        for(auto& particle : _particles)
        {
            window->draw(particle.rect);
        }
    }

    void add_black_hole(sf::Vector2i pos)
    {
        _black_holes.push_back(BHole(pos));
    }

    void add_white_hole(sf::Vector2i pos)
    {
        _white_holes.push_back(WHole(pos));
    }

    void add_particle(sf::Vector2i pos, sf::Vector2f vel)
    {
        _particles.push_back(Particle(pos, vel));
    }

    void clear(void)
    {
        _black_holes.clear();
        _white_holes.clear();
        _particles.clear();
    }
};

#endif // UNIVERSE_H
