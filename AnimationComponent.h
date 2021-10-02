//
// Created by gabriele on 02/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ANIMATIONCOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_ANIMATIONCOMPONENT_H

#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class AnimationComponent {

public:
    AnimationComponent();
    virtual ~AnimationComponent();

private:
    class Animation {
    public:
        sf::Texture& textureSheet;
        float speed;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect endRect;

        Animation(sf::Texture& textureSheet, float speed, int start_x, int start_y, int end_x, int end_y, int width, int height)
                : textureSheet(textureSheet), speed(speed), width(width), height(height)
        {
            this->width = width;
            this->height = height;
            this->startRect = sf::IntRect(start_x, start_y, width, height);
            this->endRect = sf::IntRect(end_x, end_y, width, height);
        }

        void update(const float& dt){

        }

        void pause();
        void reset();
    };

    std::map<std::string, Animation> animations;
};


#endif //DRAGHI_E_SOTTERRANEI_ANIMATIONCOMPONENT_H
