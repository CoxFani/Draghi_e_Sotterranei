//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMY_H
#define DRAGHI_E_SOTTERRANEI_ENEMY_H


#include "GameCharacter.h"

class Enemy : public GameCharacter {
public:
    Enemy(float x, float y, sf::Texture& texture_sheet);
    virtual ~Enemy();

    void updateAnimation(const float& dt);
    void update(const float &dt, sf::Vector2f& mouse_pos_view);
    void render(sf::RenderTarget &target, sf::Shader* shader, const bool show_hitbox);

private:
    void initVariables();
    void initAnimations();


};


#endif //DRAGHI_E_SOTTERRANEI_ENEMY_H
