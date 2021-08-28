//
// Created by alpacox on 26/03/21.
//

#include "State.h"

State::State(sf::RenderWindow* window) {
    this->window = window;
    this -> quit = false;
}

State::~State() {
    
}

const bool &State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

/* POINTZERO
void State::setQuit(const bool quit) {

    this -> quit = quit;
}
 */