//
// Created by alpacox on 30/03/21.
//

#include "Game.h"


Game::Game() {

    quit = false;

    this -> hero = new Hero("Beppe", 50, 16,16,10,12);

    this -> states.push(new GameState(this-> hero));

}

Game::~Game() {

    delete this -> hero;

    while ( !this -> states.empty()){

        delete this -> states.top();
        this -> states.pop();
    }
}

const bool& Game::getQuit() const{

    return this -> quit;

}

void Game::update() {

    this -> states.top()->update();

    if (this -> states.top()->getQuit()){

        delete this -> states.top();
        this -> states.pop();
    }


    if (this -> states.empty())
        this -> quit = true;

}

