//
// Created by alpacox on 27/09/21.
//
#include "GameState.h"
#include "Button.h"
#ifndef DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
#define DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H


class MainMenuState : public State {

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*>buttons;

    void iniFonts();
    void initButtons();
    void initKeybinds();

};



#endif //DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
