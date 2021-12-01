//
// Created by alpacox on 30/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMYEDITORMODE_H
#define DRAGHI_E_SOTTERRANEI_ENEMYEDITORMODE_H

#include "EditorMode.h"
#include "EnemySpawner.h"

class State;
class StateData;
class EditorMode;
class TileMap;
class Tile;
class EnemySpawner;

class EnemyEditorMode : public EditorMode{
public:
    EnemyEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data);
    virtual ~EnemyEditorMode();

    void updateInput(const float& dt) override;
    void updateGui(const float& dt) override;
    void update(const float& dt) override;

    void renderGui(sf::RenderTarget& target) override;
    void render(sf::RenderTarget& target) override;

private:
    sf::Text cursorText;
    sf::RectangleShape sidebar;
    sf::RectangleShape selectorRect;

    void initGui();
    void initVariables();
};


#endif //DRAGHI_E_SOTTERRANEI_ENEMYEDITORMODE_H
