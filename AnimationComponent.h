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
    AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
    virtual ~AnimationComponent();

    void addAnimation(const std::string key);
    void startAnimation(const std::string animation);
    void pauseAnimation(const std::string animation);
    void resetAnimation(const std::string animation);
    void update(const float& dt);

private:
    class Animation {
    public:
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float animationTimer;
        float timer;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;
//Animation non inizializza timer (fare caso quando apre class Animation{} se è una dimenticanza o se fa così)
        Animation(sf::Sprite& sprite, sf::Texture& texture_sheet, float animation_timer, int start_x, int start_y, int end_x, int end_y, int width, int height)
                : sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer), width(width), height(height)
        {
            this->startRect = sf::IntRect(start_x, start_y, width, height);
            this->currentRect = this->startRect;
            this->endRect = sf::IntRect(end_x, end_y, width, height);

            this->sprite.setTexture(this->textureSheet, true);
            this->sprite.setTextureRect(this->startRect);
        }

        void update(const float& dt){
            this->timer = 10.f * dt;
            if (this->timer >= this->animationTimer){
                this->timer = 0.f;

                if (this->currentRect != this->endRect) {
                    this->currentRect.left += this->width;
                }
                else {
                    this->currentRect.left = this->startRect.left;
                }
            }
        }

        void pause();
        void reset();
    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, Animation> animations;
};


#endif //DRAGHI_E_SOTTERRANEI_ANIMATIONCOMPONENT_H
