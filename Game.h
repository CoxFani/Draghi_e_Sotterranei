//
// Created by alpacox on 30/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAME_H
#define DRAGHI_E_SOTTERRANEI_GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include "State.h"
#include "GameState.h"
#include "GameCharacter.h"
#include "Hero.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


//POINT ZERO using namespace std;

class Game {
public:
    Game();
    virtual ~Game();

    void update(); //
    void render();
    void run();
    void updateSFMLEvents();

//POINTZERO    [[nodiscard]] const bool& getQuit() const;


private:

    sf::RenderWindow *window;
    sf::Event sfEvent;

    void initWindow();
/* POINTZERO
    bool quit;

    stack<State*> states;

    Hero* hero;
*/
};


#endif //DRAGHI_E_SOTTERRANEI_GAME_H
