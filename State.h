//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_STATE_H
#define DRAGHI_E_SOTTERRANEI_STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {

public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void render() = 0;

    /* POINTZERO
            const bool& getQuit() const;
            void setQuit(const bool quit);

            virtual void update() = 0;
        */
private:
    std::vector<sf::Texture> textures;
            //bool quit; [POINTZERO]

    };
#endif //DRAGHI_E_SOTTERRANEI_STATE_H