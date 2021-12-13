//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H

#include "GameCharacter.h"
#include "Items.h"
#include "Inventory.h"
//#include "GameState.h"

class  GameCharacter;

class Hero : public GameCharacter {
public:
    Hero(float x, float y, sf::Texture& texture_sheet);
    virtual ~Hero();

    AttributeComponent* getAttributeComponent();
    Weapon* getWeapon() const;

    const std::string toStringCharacterTab() const;
    const bool& getInitAttack() const;

    void setInitAttack(const bool initAttack);

    const bool getDamageTimer();

    const unsigned getDamage() const;

    void loseHP(const int hp);
    void gainHP(const int hp);
    void loseEXP(const int exp);
    void gainEXP(const int exp);
    void updateAttack();
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view);
    void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const sf::Vector2f light_position = sf::Vector2f() ,  const bool show_hitbox = false);


private:
    Inventory* inventory;

    bool initAttack;
    bool attacking;
    Weapon* weapon;

    sf::Clock damageTimer;
    sf::Int32 damageTimerMax;

    void initVariables();
    void initComponents();
    void initAnimations();
    void initInventory();

};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
