//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H
#define DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H

#include "Weapon.h"
#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class HitboxComponent;
class MovementComponent;
class AnimationComponent;

class GameCharacter {
public:
    GameCharacter();
    virtual ~GameCharacter();

    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    virtual const sf::Vector2f& getPosition() const;
    virtual const sf::FloatRect getGlobalBounds() const;
    virtual const sf::Vector2u getGridPosition(const unsigned gridSizeU) const;
    virtual const sf::FloatRect getNextPositionBounds(const float& dt) const;

    virtual void setPosition(const float x, const float y);

    virtual void move(const float x, const float y, const float& dt);
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void stopVelocity();
    virtual void stopVelocityX();
    virtual void stopVelocityY();


protected:
    sf::Sprite sprite;

    HitboxComponent* hitboxComponent;
    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

private:
    void initVariables();



};

#endif //DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H