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
    void updateButtons();
    void updatePauseMenuButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::Font font;
    PauseMenu* pmenu;

    std::map<std::string, gui::Button*>buttons;

    TileMap map;

    void initVariables();
    void initBackground();
    void iniFonts();
    void initButtons();
    void initKeybinds();
    void initPausedMenu();


};


#endif //DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
