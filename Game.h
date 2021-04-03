//
// Created by alpacox on 30/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAME_H
#define DRAGHI_E_SOTTERRANEI_GAME_H

#include <iostream>
#include <vector>
#include <stack>
#include "State.h"
#include "GameState.h"
#include "GameCharacter.h"
#include "Hero.h"

using namespace std;

class Game {
public:
    Game();
    virtual ~Game();

    void update(); //
    [[nodiscard]] const bool& getQuit() const;


private:
    bool quit;
    stack<State*> states;

    Hero* hero;

};


#endif //DRAGHI_E_SOTTERRANEI_GAME_H
