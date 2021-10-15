//
// Created by alpacox on 26/03/21.
//

#include "State.h"

State::State(StateData* state_data) {
    this->stateData = state_data;
    this->window = state_data->window;
    this->supportedKeys = state_data->supportedKeys;
    this->states = state_data->states;
    this->quit = false;
    this->paused = false;
    this->keyTime = 0.f;
    this->keyTimeMax = 10.f;
    this->gridSize = state_data->gridSize;
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

void State::pauseState() {
    this->paused = true;
}

void State::unpauseState() {
    this->paused = false;
}

void State::updateKeyTime(const float& dt) {
    if(this->keyTime < this->keyTimeMax)
        this->keyTime += 100.f * dt;
}

const bool State::getKeyTime() {
    if(this->keyTime >= this->keyTimeMax){
        this->keyTime = 0.f;
        return true;
    }
    return false;

}

/* POINTZERO
void State::setQuit(const bool quit) {

    this -> quit = quit;
}
 */