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
#include "Hero.h"

using namespace std;

class GameState: public State{

public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

    /* POINTZERO
    explicit GameState(Hero* hero);
    virtual ~GameState();

    void printMenu() const;
    const int getChoice() const;
    void updateMenu();
    virtual void update();
    */
private:

         /* POINTZERO
    Hero* hero;
*/

};

#endif //DRAGHI_E_SOTTERRANEI_GAMESTATE_H
