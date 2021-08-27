//
// Created by alpacox on 26/03/21.
//

#include "State.h"

State::State(sf::RenderWindow* window) {
    this->window = window;
    //this -> quit = false; [POINTZERO]
}

State::~State() {
    
}

/* POINTZERO
const bool & State::getQuit() const {
    return  this -> quit;
}

void State::setQuit(const bool quit) {

    this -> quit = quit;
}
 */