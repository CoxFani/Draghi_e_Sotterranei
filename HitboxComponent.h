//
// Created by alpacox on 05/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HITBOXCOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_HITBOXCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class HitboxComponent {
public:
    HitboxComponent(sf::Sprite& sprite,
                    float offset_x, float offset_y,
                    float width, float height);
    ~HitboxComponent();

    bool checkIntersect(const sf::FloatRect& frect);

    void update();
    void render(sf::RenderTarget& target);

private:
    sf::RectangleShape hitbox;
    sf::Sprite& sprite;
    float offsetX;
    float offsetY;

};


#endif //DRAGHI_E_SOTTERRANEI_HITBOXCOMPONENT_H
