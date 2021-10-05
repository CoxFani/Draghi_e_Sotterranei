//
// Created by alpacox on 05/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
#define DRAGHI_E_SOTTERRANEI_EDITORSTATE_H

#include "State.h"
#include "Button.h"

class EditorState :
        public State{
public:

    EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    ~EditorState() override;

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);

private:
    sf::Font font;

    std::map<std::string, Button*>buttons;

    void initVariables();
    void initBacground();
    void iniFonts();
    void initButtons();
    void initKeybinds();


};


#endif //DRAGHI_E_SOTTERRANEI_EDITORSTATE_H
