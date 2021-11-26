//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H
#define DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H

#include "Weapon.h"
#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "AttributeComponent.h"
#include "SkillComponent.h"

class HitboxComponent;
class MovementComponent;
class AnimationComponent;
class AttributeComponent;
class SkillComponent;

class GameCharacter {
public:
    GameCharacter();
    virtual ~GameCharacter();

    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);
    void createAttributeComponent(const unsigned level);
    void createSkillComponent();

    virtual const sf::Vector2f& getPosition() const;
    virtual const sf::Vector2f getCenter() const;

    virtual const sf::FloatRect getGlobalBounds() const;
    virtual const sf::Vector2i getGridPosition(const int gridSizeI) const;
    virtual const sf::FloatRect getNextPositionBounds(const float& dt) const;

    virtual void setPosition(const float x, const float y);

    virtual void move(const float x, const float y, const float& dt);
    virtual void update(const float& dt, sf::Vector2f& mouse_pos_view) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader, const bool show_hitbox) = 0;
    virtual void stopVelocity();
    virtual void stopVelocityX();
    virtual void stopVelocityY();


protected:
    sf::Sprite sprite;

    HitboxComponent* hitboxComponent;
    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;
    AttributeComponent* attributeComponent;
    SkillComponent* skillComponent;


private:
    void initVariables();

};

#endif //DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H