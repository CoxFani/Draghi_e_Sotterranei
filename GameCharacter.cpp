//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "GameCharacter.h"
#include "Dice.h"

GameCharacter::GameCharacter() {
    this->initVariables();
}

GameCharacter::~GameCharacter() {

    delete this->hitboxComponent;
    delete this->movementComponent;
    delete this->animationComponent;

}

void GameCharacter::move(const float dir_x, const float dir_y,const float& dt) {
    if(this->movementComponent)
        this->movementComponent->move(dir_x, dir_y, dt);
}

void GameCharacter::update(const float &dt) {

}

void GameCharacter::render(sf::RenderTarget& target) {


}

void GameCharacter::setTexture(sf::Texture& texture) {
    this->sprite.setTexture(texture);
}

void GameCharacter::initVariables() {

    this->hitboxComponent = nullptr;
    this->movementComponent = nullptr;
    this->animationComponent = nullptr;
}

void GameCharacter::setPosition(const float x, const float y) {

    if(this->hitboxComponent)
        this->hitboxComponent->setPosition(x, y);
    else
        this->sprite.setPosition(x, y);

}

void GameCharacter::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {

    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);

}

void GameCharacter::createAnimationComponent(sf::Texture &texture_sheet) {

    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void GameCharacter::createHitboxComponent(sf::Sprite &sprite, float offset_x, float offset_y, float width, float height) {

    this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

const sf::Vector2f &GameCharacter::getPosition() const {

    if(this->hitboxComponent)
        return this->hitboxComponent->getPosition();

    return this->sprite.getPosition();
}

const sf::FloatRect GameCharacter::getGlobalBounds() const {

    if(this->hitboxComponent)
        return this->hitboxComponent->getGlobalBounds();
    return this->sprite.getGlobalBounds();
}
