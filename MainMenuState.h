//
// Created by alpacox on 27/09/21.
//
#include "GameState.h"
#include "EditorState.h"
#include "SettingState.h"
#include "Gui.h"
#ifndef DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
#define DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H


class MainMenuState : public State {

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*>buttons;

    void initVariables();
    void initBackground();
    void iniFonts();
    void initButtons();
    void initKeybinds();

};



#endif //DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
