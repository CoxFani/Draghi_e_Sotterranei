//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H

#include "GameCharacter.h"
#include "Sword.h"
//#include "GameState.h"

class  GameCharacter;

class Hero : public GameCharacter {
public:
    Hero(float x, float y, sf::Texture& texture_sheet);
    virtual ~Hero();

    AttributeComponent* getAttributeComponent();

    void loseHP(const int hp);
    void gainHP(const int hp);
    void loseEXP(const int exp);
    void gainEXP(const int exp);
    void updateAttack();
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view);



    void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const bool show_hitbox = false);

private:
    bool attacking;
    Sword sword;


    void initVariables();
    void initComponents();
    void initAnimations();

protected:

};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
