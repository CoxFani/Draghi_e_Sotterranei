//
// Created by alpacox on 30/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAME_H
#define DRAGHI_E_SOTTERRANEI_GAME_H

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

    void updateDt();
    void update();
    void render();
    void run();
    void updateSFMLEvents();

//POINTZERO    [[nodiscard]] const bool& getQuit() const;


private:

    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    stack<State*> states;

    void initWindow();
    void initStates();
/* POINTZERO
    bool quit;

    stack<State*> states;

    Hero* hero;
*/
};


#endif //DRAGHI_E_SOTTERRANEI_GAME_H
