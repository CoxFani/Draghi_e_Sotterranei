//
// Created by alpacox on 30/03/21.
//

#include "Game.h"


Game::Game() {

    this->initWindow();
    this->initStates();

/* POINTZERO
    quit = false;

    this -> hero = new Hero("Beppe", 50, 16,16,10,12);

    this -> states.push(new GameState(this-> hero));
*/
}

Game::~Game() {

    delete this->window;

    while(this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
/* POINTZERO
    delete this -> hero;

    while ( !this -> states.empty()){

        delete this -> states.top();
        this -> states.pop();
    }
}

const bool& Game::getQuit() const{

    return this -> quit;
*/
}

void Game::initWindow() {

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::update() {

    this->updateSFMLEvents();

    if(!this->states.empty())
        this->states.top()->update(this->dt);


/* POINTZERO
    this -> states.top()->update();

    if (this -> states.top()->getQuit()){

        delete this -> states.top();
        this -> states.pop();
    }


    if (this -> states.empty())
        this -> quit = true;
*/
}
void Game::render() {

    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render();

    this->window->display();

}

void Game::run() {

    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

void Game::updateSFMLEvents() {

    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }

}

void Game::updateDt() {

    this->dt = this->dtClock.restart().asSeconds();


}

void Game::initStates() {
    this->states.push(new GameState(this->window));
}

