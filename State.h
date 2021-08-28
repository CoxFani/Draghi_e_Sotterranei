//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_STATE_H
#define DRAGHI_E_SOTTERRANEI_STATE_H

#include "GameCharacter.h"

class State {

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

    /* POINTZERO
            const bool& getQuit() const;
            void setQuit(const bool quit);

            virtual void update() = 0;
        */
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;

private:

    };
#endif //DRAGHI_E_SOTTERRANEI_STATE_H