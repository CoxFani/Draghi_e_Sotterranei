//
// Created by alpacox on 29/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_EDITORMODE_H
#define DRAGHI_E_SOTTERRANEI_EDITORMODE_H

#include "State.h"
#include "TileMap.h"
#include "Gui.h"

class State;
class StateData;
class TileMap;
class Tile;

class EditorMode {
public:
    EditorMode(StateData* state_data, TileMap* tile_map, sf::Font* font);
    virtual ~EditorMode();

    virtual void updateInput(const float& dt) = 0;
    virtual void updateGui(const float& dt) = 0;
    virtual void update(const float& dt) = 0;

    virtual void renderGui(sf::RenderTarget& target) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
    StateData* stateData;
    TileMap* tileMap;
    sf::Font* font;

};


#endif //DRAGHI_E_SOTTERRANEI_EDITORMODE_H
