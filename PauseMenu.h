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
    PauseMenu(sf::RenderWindow& window);
    virtual ~PauseMenu();

    void update();
    void render(sf::RenderTarget& target);

private:
    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, Button*> buttons;

};


#endif //DRAGHI_E_SOTTERRANEI_PAUSEMENU_H
