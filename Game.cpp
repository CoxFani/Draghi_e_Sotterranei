//
// Created by alpacox on 30/03/21.
//

#include "Game.h"


Game::Game() {

    quit = false;

    this -> gameCharacter = new GameCharacter("Beppe", 50, 16,16,10,12);

    this -> states.push(new GameState(this->gameCharacter));

}

Game::~Game() {

    delete this ->gameCharacter;

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

