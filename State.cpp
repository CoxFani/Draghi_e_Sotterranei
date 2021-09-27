//
// Created by alpacox on 26/03/21.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) {
    this->window = window;
    this->supportedKeys = supportedKeys;
    this -> quit = false;
}

State::~State() {
    
}

const bool & State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
    {
        this->quit = true;
    }
}

/* POINTZERO
void State::setQuit(const bool quit) {

    this -> quit = quit;
}
 */