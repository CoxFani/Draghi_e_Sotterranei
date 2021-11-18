//
// Created by alpacox on 26/03/21.
//

#include "precompiler.h"
#include "State.h"

State::State(StateData* state_data) {
    this->stateData = state_data;
    this->window = state_data->window;
    this->supportedKeys = state_data->supportedKeys;
    this->states = state_data->states;
    this->quit = false;
    this->paused = false;
    this->keyTime = 0.f;
    this->keyTimeMax = 25.f;
    this->gridSize = state_data->gridSize;
}

State::~State() {
    
}

const bool & State::getQuit() const {
    return this->quit;
}

const bool State::getKeyTime() {
    if(this->keyTime >= this->keyTimeMax){
        this->keyTime = 0.f;
        return true;
    }
    return false;
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

void State::updateMousePosition(sf::View* view) {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
   if(view)
       this->window->setView(*view);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
    this->mousePosGrid = sf::Vector2i(
            static_cast<int>(this->mousePosView.x) / static_cast<int>(this->gridSize) ,
            static_cast<int>(this->mousePosView.y) / static_cast<int>(this->gridSize)
    );
    this->window->setView(this->window->getDefaultView());
}

void State::updateKeyTime(const float& dt) {
    if(this->keyTime < this->keyTimeMax)
        this->keyTime += 100.f * dt;
}

const float State::p2pX(const float perc) const{
    /*
     * Convertire un valore percentuale in pixelsrelativamente alla risoluzione corrente nelle ascisse x.
     *
     * @param float perc        Il valore percentuale.
     *
     * @return float            Il valore calcolato in pixels.
     */
    return std::floor(static_cast<float>(this->stateData->gfxSettings->resolution.width) * (perc/100.f));
}

const float State::p2pY(const float perc) const{
    /*
    * Convertire un valore percentuale in pixelsrelativamente alla risoluzione corrente nelle ordinate y.
    *
    * @param float perc        Il valore percentuale.
    *
    * @return float            Il valore calcolato in pixels.
    */
    return std::floor(static_cast<float>(this->stateData->gfxSettings->resolution.height) * (perc/100.f));

}

const unsigned State::calcCharSize() const {
    /*
    * Calcola la dimensione del testo usando la risoluzione corrente e una costante
    *
    *
    * @return unsigned            Il valore calcolato della dimensione del testo.
    */

    return static_cast<unsigned>((this->stateData->gfxSettings->resolution.width + this->stateData->gfxSettings->resolution.height)/40); // (1280 + 720) / 50 = 40 dove 50 è la vecchia dimensione de testo standard
}



