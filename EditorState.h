//
// Created by alpacox on 05/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
#define DRAGHI_E_SOTTERRANEI_EDITORSTATE_H

#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"

class State;
class Gui;
class PauseMenu;
class TileMap;

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
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void renderGui(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::Font font;
    sf::Text cursorText;
    PauseMenu* pmenu;

    std::map<std::string, gui::Button*>buttons;

    TileMap* tileMap;

    sf::RectangleShape sidebar;

    sf::IntRect textureRect;
    sf::RectangleShape selectorRect;

    gui::TextureSelector* textureSelector;

    void initVariables();
    void initBackground();
    void initFonts();
    void initText();
    void initButtons();
    void initKeybinds();
    void initPausedMenu();
    void initGui();
    void initTileMap();

};


#endif //DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
