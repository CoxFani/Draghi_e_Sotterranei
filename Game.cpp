//
// Created by alpacox on 30/03/21.
//

#include "Game.h"


Game::Game() {

    this->initWindow();
    this->initKeys();
    this->initStates();

/* POINTZERO
    quit = false;

    this -> hero = new Hero("Beppe", 50, 16,16,10,12);

    this -> states.push(new GameState(this-> hero));
*/
}

Game::~Game() {

    delete this->window;

    while(!this->states.empty())
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

void Game::initKeys() {

    /* TODO sostituire comandi con file
     std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close(); */

    this->supportedKeys["Escape"] = sf::Keyboard::Escape;
    this->supportedKeys["A"] = sf::Keyboard::A;
    this->supportedKeys["D"] = sf::Keyboard::D;
    this->supportedKeys["W"] = sf::Keyboard::W;
    this->supportedKeys["S"] = sf::Keyboard::S;

    //for debug (da rimuovere)
    for (auto i : this->supportedKeys)
        {
            std::cout << i.first << " " << i.second << "/n";
        }
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &this->supportedKeys));
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

void Game::endApplication() {
    std::cout << "Ending Application!" << "/n";
}

