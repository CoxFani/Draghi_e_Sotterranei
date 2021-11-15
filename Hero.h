//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H

#include "GameCharacter.h"
//#include "GameState.h"

class  GameCharacter;

class Hero : public GameCharacter {
public:
    Hero(float x, float y, sf::Texture& texture_sheet);
    virtual ~Hero();

    AttributeComponent* getAttributeComponent();

    void updateAttack();
    void updateAnimation(const float& dt);
    void update(const float& dt);
    //TODO definire
    void loseHP(const int hp);
    void loseEXP(const int exp);
    void gainHP(const int hp);
    void gainEXP(const int exp);

    void render(sf::RenderTarget& target);

private:
    bool attacking;

    void initVariables();
    void initComponents();

protected:

};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
