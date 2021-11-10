//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMESTATE_H
#define DRAGHI_E_SOTTERRANEI_GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"

class State;
class PauseMenu;
class TileMap;

using namespace std;

class GameState: public State {

public:
    GameState(StateData* state_data);
    virtual ~GameState();

    void updateView(const float& dt);
    void updateInput(const float& dt);
    void updateHeroInput(const float& dt);
    void updatePauseMenuButtons();
    void updateTileMap(const float& dt);
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
    sf::View view;
    sf::RenderTexture renderTexture;
    sf::Sprite renderSprite;

    sf::Font font;
    PauseMenu* pmenu;

    Hero* hero;
    sf::Texture texture;

    TileMap* tileMap;

    void initView();
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPausedMenu();
    void initHeroes();
    void initTileMap();
    void initDeferredRender();

};

#endif //DRAGHI_E_SOTTERRANEI_GAMESTATE_H
