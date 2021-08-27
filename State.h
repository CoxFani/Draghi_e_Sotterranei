//
// Created by alpacox on 26/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_STATE_H
#define DRAGHI_E_SOTTERRANEI_STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {

public:
    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void endState() = 0;

    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

    /* POINTZERO
            const bool& getQuit() const;
            void setQuit(const bool quit);

            virtual void update() = 0;
        */
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
            //bool quit; [POINTZERO]

    };
#endif //DRAGHI_E_SOTTERRANEI_STATE_H