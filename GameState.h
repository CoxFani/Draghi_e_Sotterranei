//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMESTATE_H
#define DRAGHI_E_SOTTERRANEI_GAMESTATE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "State.h"
#include "GameCharacter.h"

using namespace std;

class GameState: public State{

public:
    explicit GameState( GameCharacter* gameCharacter);
    virtual ~GameState();

    void printMenu() const;
    const int getChoice() const;
    void updateMenu();
    virtual void update();

private:
    GameCharacter* gameCharacter;


};


#endif //DRAGHI_E_SOTTERRANEI_GAMESTATE_H
