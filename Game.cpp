//
// Created by alpacox on 30/03/21.
//

#include "precompiler.h"
#include "Game.h"

Game::Game() {

    this->initVariables();
    this->initGraphicsSettings();
    this->initWindow();
    this->initKeys();
    this->initStateData();
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



    if(this->gfxSettings.fullscreen)
       this->window = new sf::RenderWindow(
               this->gfxSettings.resolution,
               this->gfxSettings.title,
               sf::Style::Fullscreen,
               this->gfxSettings.contextSettings);
    else
        this->window = new sf::RenderWindow(
                this->gfxSettings.resolution,
                this->gfxSettings.title,
                sf::Style::Titlebar | sf::Style::Close,
                this->gfxSettings.contextSettings);

    this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
    this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
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
    this->states.push(new MainMenuState(&this->stateData));

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

    this->dt = 0.f;

    this->gridSize = 50.f;

}

void Game::initGraphicsSettings() {

    this->gfxSettings.loadFromFile("../Config/graphics.ini");





}

void Game::initStateData() {

    this->stateData.window = this->window;
    this->stateData.gfxSettings = &this->gfxSettings;
    this->stateData.supportedKeys = &this->supportedKeys;
    this->stateData.states = &this->states;
    this->stateData.gridSize = this->gridSize;
}

