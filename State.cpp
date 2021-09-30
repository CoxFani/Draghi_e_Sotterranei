//
// Created by alpacox on 26/03/21.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,     std::stack<State*>* states) {
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->states = states;
    this->quit = false;
}

State::~State() {
    
}

const bool & State::getQuit() const {
    return this->quit;

}

void State::updateMousePosition() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::endState() {
    this->quit = true;

}

/* POINTZERO
void State::setQuit(const bool quit) {

    this -> quit = quit;
}
 */