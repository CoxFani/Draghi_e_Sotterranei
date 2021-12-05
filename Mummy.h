//
// Created by alpacox on 02/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MUMMY_H
#define DRAGHI_E_SOTTERRANEI_MUMMY_H

#include "Enemy.h"

class Mummy:
        public Enemy{
public:
    Mummy(float x, float y, sf::Texture& texture_sheet);
    virtual ~Mummy();

    void updateAnimation(const float& dt) override;
    void update(const float &dt, sf::Vector2f& mouse_pos_view) override;
    void render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox) override;

private:
    void initVariables() override;
    void initAnimations() override;

};


#endif //DRAGHI_E_SOTTERRANEI_MUMMY_H
