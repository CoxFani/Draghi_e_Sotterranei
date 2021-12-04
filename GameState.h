//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMESTATE_H
#define DRAGHI_E_SOTTERRANEI_GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "HeroGUI.h"
#include "Sword.h"
#include "Bow.h"

using namespace std;

class GameState: public State {
public:
    GameState(StateData* state_data);
    virtual ~GameState();

    void updateView(const float& dt);
    void updateInput(const float& dt);
    void updateHeroInput(const float& dt);
    void updateHeroGUI(const float& dt);
    void updatePauseMenuButtons();
    void updateTileMap(const float& dt);
    void updateHero(const float& dt);
    void updateEnemies(const float& dt);
    void updateCombat(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::View view;
    sf::Vector2i viewGridPosition;
    sf::RenderTexture renderTexture;
    sf::Sprite renderSprite;

    sf::Font font;
    PauseMenu* pmenu;

    sf::Shader core_shader;

    Hero* hero;
    HeroGUI* heroGUI;
    sf::Texture texture;

    TileMap* tileMap;

    std::vector<Enemy*> activeEnemies;
    EnemyStrategy *enemyStrategy;

    void initView();
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPausedMenu();
    void initShaders();
    void initHeroes();
    void initHeroGUI();
    void initTileMap();
    void initDeferredRender();
    void initEnemyStrategy();

};

#endif //DRAGHI_E_SOTTERRANEI_GAMESTATE_H
