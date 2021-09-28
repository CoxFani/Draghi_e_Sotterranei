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
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::RectangleShape background;
    sf::Font font;

    Button *gamestate_btn;

    void iniFonts();
    void initKeybinds();

};



#endif //DRAGHI_E_SOTTERRANEI_MAINMENUSTATE_H
