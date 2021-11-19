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
    SettingState(StateData* state_data);
    virtual ~SettingState();

    void updateInput(const float& dt);
    void updateGui(const float& dt);
    void update(const float& dt);
    void renderGui(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*> buttons;
    std::map<std::string, gui::DropDownList*> dropdownList;

    sf::Text optionsText;

    std::vector<sf::VideoMode> modes;

    void initVariables();
    void iniFonts();
    void initGui();
    void initKeybinds();
    void resetGui();

};


#endif //DRAGHI_E_SOTTERRANEI_SETTINGSTATE_H
