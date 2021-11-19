//
// Created by alpacox on 27/09/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
#define DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H

#include "GameState.h"
#include "EditorState.h"
#include "SettingState.h"
#include "Gui.h"

class MainMenuState : public State {

public:
    MainMenuState(StateData* state_data);
    virtual ~MainMenuState();

    void updateInput(const float& dt);
    void updateGui();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);


private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*>buttons;

    void initVariables();
    void iniFonts();
    void initGui();
    void initKeybinds();
    void resetGui();

};



#endif //DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
