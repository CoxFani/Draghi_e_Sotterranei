//
// Created by alpacox on 28/09/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_BUTTON_H
#define DRAGHI_E_SOTTERRANEI_BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>



#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {

public:
    Button(float x, float y, float width, float hight, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    const bool isPressed() const;

    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);


private:
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
};


#endif //DRAGHI_E_SOTTERRANEI_BUTTON_H
