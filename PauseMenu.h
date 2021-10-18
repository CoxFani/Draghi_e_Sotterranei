//
// Created by alpacox on 08/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
#define DRAGHI_E_SOTTERRANEI_PAUSEMENU_H

#include "Gui.h"


class PauseMenu {
public:
    PauseMenu(sf::RenderWindow& window, sf::Font& font);
    virtual ~PauseMenu();

    std::map<std::string, gui::Button*>& getButtons();

    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::Font& font;
    sf::Text menuText;
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, gui::Button*> buttons;

};


#endif //DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
