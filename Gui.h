//
// Created by alpacox on 28/09/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GUI_H
#define DRAGHI_E_SOTTERRANEI_GUI_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

namespace gui {

    class Button {

    public:
        Button(float x, float y, float width, float height,
            sf::Font *font, std::string text, unsigned character_size,
            sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
            sf::Color idle_color, sf::Color hover_color, sf::Color active_color);

        ~Button();

        const bool isPressed() const;

        const std::string& getText() const;

        void setText(const std::string text);

        void update(const sf::Vector2f &mousePos);

        void render(sf::RenderTarget &target);


    private:
        short unsigned buttonState;

        sf::RectangleShape shape;
        sf::Font *font;
        sf::Text text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;
    };

//**************************** DROP DOWN LIST *********************************

    class DropDownList{

    public:

        DropDownList(float x, float y, float width, float height, sf::Font& font, std::string list[], unsigned elements, unsigned default_index = 0);
        ~DropDownList();

        void update(const sf::Vector2f &mousePos, const float& dt);
        void render(sf::RenderTarget &target);

        const bool getKeytime();
        void updateKeytime(const float& dt);

    private:
        float keytime;
        float keytimeMax;

        sf::Font& font;
        gui::Button* activeElement;
        std::vector<gui::Button*> list;
        bool showList;

    };

}
#endif //DRAGHI_E_SOTTERRANEI_GUI_H
