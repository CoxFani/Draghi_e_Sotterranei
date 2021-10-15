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
#include "PauseMenu.h"
#include "TileMap.h"

using namespace std;

class GameState: public State {

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    void updateInput(const float& dt);
    void updateHeroInput(const float& dt);
    void updatePauseMenuButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

    //id keybinds;

    /* POINTZERO
    explicit GameState(Hero* hero);
    virtual ~GameState();

    void printMenu() const;
    const int getChoice() const;
    void updateMenu();
    virtual void update();
    */
private:
    sf::Font font;
    PauseMenu* pmenu;

    Hero* hero;
    sf::Texture texture;

    TileMap map;

    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPausedMenu();
    void initHeroes();

};

#endif //DRAGHI_E_SOTTERRANEI_GAMESTATE_H
