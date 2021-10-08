//
// Created by alpacox on 08/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
#define DRAGHI_E_SOTTERRANEI_PAUSEMENU_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

#include "Button.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class PauseMenu {
public:
    PauseMenu(sf::RenderWindow& window, sf::Font& font);
    virtual ~PauseMenu();

    std::map<std::string, Button*>& getButtons();

    const bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderTarget& target);

private:
    sf::Font& font;
    sf::Text menuText;
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, Button*> buttons;

};


#endif //DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
