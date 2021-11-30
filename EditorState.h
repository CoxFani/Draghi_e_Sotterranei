//
// Created by alpacox on 05/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
#define DRAGHI_E_SOTTERRANEI_EDITORSTATE_H

#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "DefaultEditorMode.h"

class State;
class StateData;
class Gui;
class PauseMenu;
class TileMap;
class Tile;
class EditorMode;
class DefaultEditorMode;
class EditorStateData;

enum EditorModes { DEFAULT_MODE = 0, ENEMY_MODE};

class EditorState :
        public State{
public:

    EditorState(StateData* state_data);
    ~EditorState() override;

    void updateInput(const float& dt);
    void updateEditorInput(const float& dt);
    void updateButtons();
    void updateGui(const float& dt);
    void updatePauseMenuButtons();
    void updateModes(const float& dt);
    void update(const float& dt);

    void renderButtons(sf::RenderTarget& target);
    void renderGui(sf::RenderTarget& target);
    void renderModes(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

private:
    EditorStateData editorStateData;

    sf::View view;
    float cameraSpeed;
    sf::Font font;
    PauseMenu* pmenu;

    std::map<std::string, gui::Button*>buttons;

    TileMap* tileMap;

    std::vector<EditorMode*> modes;


    void initVariables();
    void initEditorStateData();
    void initFonts();
    void initButtons();
    void initKeybinds();
    void initPausedMenu();
    void initGui();
    void initTileMap();
    void initView();

    void initModes();

};


#endif //DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
