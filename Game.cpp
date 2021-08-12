//
// Created by alpacox on 30/03/21.
//

#include "Game.h"


Game::Game() {

    this->initWindow();

/* POINTZERO
    quit = false;

    this -> hero = new Hero("Beppe", 50, 16,16,10,12);

    this -> states.push(new GameState(this-> hero));
*/
}

Game::~Game() {

    delete this->window;

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

    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "DRAGHI_E_SOTTERRANEI");

}

void Game::update() {

    this->updateSFMLEvents();

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

    this->window->display();

}

void Game::run() {

    while (this->window->isOpen())
    {
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

