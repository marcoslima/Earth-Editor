
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <universe.h>

using namespace sf;
using namespace std;

void input();


enum Material{ none, bHole, particle, wHole };

class PenType
{
public:
    typedef enum {zero, rand, line, shoot, pen_type_qtd} pen_type_t;
private:
    vector<String> _vec_names = {"Zero",
                                 "Rand",
                                 "Line",
                                 "Shoot"};

    pen_type_t _pen_type = zero;

public:
    PenType()
    {
        _pen_type = zero;
    }
    PenType(pen_type_t pen_type) : _pen_type(zero) {}

    String name()
    {
        return _vec_names[_pen_type];
    }

    PenType next(void)
    {
        _pen_type = static_cast<pen_type_t>((static_cast<int>(_pen_type) + 1) % pen_type_qtd);
        return *this;
    }

    bool operator==(pen_type_t val)
    {
        return val == _pen_type;
    }
};


//enum class PenType{ zero, rand, line, shoot, qtd};

sf::RenderWindow *window;
sf::ContextSettings settings;

Universe g_universe;

Material material = none;
PenType pen = PenType(PenType::zero);


int main()
{
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow( sf::VideoMode::getDesktopMode(),
        "Earth-Editor", sf::Style::Titlebar | sf::Style::Close | sf::Style::Default,
        settings);
    window->setFramerateLimit(60);
    // window->setKeyRepeatEnabled(false);

    while (window->isOpen())
    {
        input();
        window->clear(sf::Color(5, 5, 5));

        g_universe.tick();
        g_universe.draw(window);

        sf::Font fntPenType;
        fntPenType.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
        sf::Text txtPenType(sf::String("PenType: ") + pen.name(), fntPenType);
        txtPenType.setPosition(0,0);
        window->draw(txtPenType);

        window->display();
    }
    return 0;
}

void input()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window->close();
                break;

            case Event::KeyPressed:
            {
                switch(event.key.code)
                {
                    case Keyboard::P:
                        pen.next();
                        break;

                    case Keyboard::R:
                        g_universe.clear();
                        break;

                    case Keyboard::Q:
                        window->close();
                        break;

                    case Keyboard::Num0:
                        material = none;
                        break;

                    case Keyboard::Num1:
                        material = particle;
                        break;

                    case Keyboard::Num2:
                        material = bHole;
                        break;

                    case Keyboard::Num3:
                        material = wHole;
                        break;
                }//switch(event.key.code)
            }//case Event::KeyPressed:
        }//switch(event.type)

        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            sf::Vector2f velocity(rand() % 5 - 2, rand() % 5 - 2);
            if(pen == PenType::zero)
            {
                velocity = sf::Vector2f(0,0);
            }
            switch(material)
            {
            case Material(particle):
                g_universe.add_particle( sf::Mouse::getPosition(*window), velocity);
                break;

            case Material(bHole):
                g_universe.add_black_hole(sf::Mouse::getPosition(*window));
                break;

            case Material(wHole):
                g_universe.add_white_hole( sf::Mouse::getPosition(*window) );
                break;
            }
        }
    }
}



