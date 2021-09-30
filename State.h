//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_STATE_H
#define DRAGHI_E_SOTTERRANEI_STATE_H

#include "GameCharacter.h"

class State {

public:
    State(sf::RenderWindow* window,  std::map<std::string, int>* supportedKeys,     std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    void endState();

    virtual void updateMousePosition();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;



    /* POINTZERO
            const bool& getQuit() const;
            void setQuit(const bool quit);

            virtual void update() = 0;
        */
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;


    std::vector<sf::Texture> textures;

    virtual void initKeybinds() = 0;

private:

    };
#endif //DRAGHI_E_SOTTERRANEI_STATE_H