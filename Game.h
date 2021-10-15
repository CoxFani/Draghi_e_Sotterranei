//
// Created by alpacox on 30/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAME_H
#define DRAGHI_E_SOTTERRANEI_GAME_H

#include <vector>
#include <stack>
#include "State.h"
#include "GameCharacter.h"
#include "Hero.h"
#include "MainMenuState.h"

class State;
class GameCharacter;
class Hero;
class MainMenuState;

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

    GraphicsSettings gfxSettings;
    StateData stateData;
    sf::RenderWindow *window;
    sf::Event sfEvent;


    sf::Clock dtClock;
    float dt;

    //sf::Keyboard supportedKeys;
    stack<State*> states;
    map<std::string, int> supportedKeys;

    float gridSize;

    void initVariables();
    void initGraphicsSettings();
    void initStateData();
    void initWindow();
    void initKeys();
    void initStates();
    void endApplication();

/* POINTZERO
    bool quit;

    stack<State*> states;

    Hero* hero;
*/

};


#endif //DRAGHI_E_SOTTERRANEI_GAME_H
