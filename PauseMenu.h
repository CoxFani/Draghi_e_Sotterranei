//
// Created by alpacox on 08/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
#define DRAGHI_E_SOTTERRANEI_PAUSEMENU_H

#include "State.h"
#include "Gui.h"

class Gui;

class PauseMenu {
public:
    PauseMenu(sf::VideoMode& vm, sf::Font& font, bool type);
    virtual ~PauseMenu();

    std::map<std::string, gui::Button*>& getButtons();

    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, const float y, const float width, const float height, const unsigned char_size, const std::string text);

    void update(const sf::Vector2i& mousePosWindow);
    void render(sf::RenderTarget& target);

private:
    sf::Font& font;
    sf::Text menuText;
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, gui::Button*> buttons;

};


#endif //DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
