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

    std::ifstream ifs("../Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }

    ifs.close();

    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasing_level;

    if(this->fullscreen)
       this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys() {

     std::ifstream ifs("../Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();
/*
    this->supportedKeys["Escape"] = sf::Keyboard::Escape;
    this->supportedKeys["A"] = sf::Keyboard::A;
    this->supportedKeys["D"] = sf::Keyboard::D;
    this->supportedKeys["W"] = sf::Keyboard::W;
    this->supportedKeys["S"] = sf::Keyboard::S;
*/
    //for debug (da rimuovere)
    for (auto i : this->supportedKeys)
        {
            std::cout << i.first << " " << i.second << "\n";
        }
}

void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));

}

void Game::update() {

    this->updateSFMLEvents();

    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
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
    std::cout << "Termina il gioco!" << "\n";
}

void Game::initVariables() {
    this->window = nullptr;
    this->fullscreen = false;

    this->dt = 0.f;

}
