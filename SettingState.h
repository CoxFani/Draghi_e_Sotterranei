//
// Created by alpacox on 08/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_SETTINGSTATE_H
#define DRAGHI_E_SOTTERRANEI_SETTINGSTATE_H

#include "State.h"
#include "Gui.h"

class SettingState :
        public State {
public:
    SettingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~SettingState();

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

    gui::DropDownList* ddl;

    void initVariables();
    void initBackground();
    void iniFonts();
    void initButtons();
    void initKeybinds();

};


#endif //DRAGHI_E_SOTTERRANEI_SETTINGSTATE_H
