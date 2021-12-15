//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "GameCharacter.h"
#include "Dice.h"

GameCharacter::GameCharacter() {
    initVariables();
}

GameCharacter::~GameCharacter() {
    delete hitboxComponent;
    delete movementComponent;
    delete animationComponent;
    delete attributeComponent;
    delete skillComponent;
}

void GameCharacter::move(const float dir_x, const float dir_y,const float& dt) {
    if(movementComponent)
        movementComponent->move(dir_x, dir_y, dt);

    if(this->skillComponent){
        skillComponent->gainExp(SKILLS::ENDURANCE, 1);
        //std::cout << skillComponent->getSkill(SKILLS::ENDURANCE) << "\n";

    }
}

void GameCharacter::setTexture(sf::Texture& texture) {

    sprite.setTexture(texture);
}

void GameCharacter::initVariables() {

    hitboxComponent = nullptr;
    movementComponent = nullptr;
    animationComponent = nullptr;
    attributeComponent = nullptr;
    skillComponent = nullptr;
}

void GameCharacter::setPosition(const float x, const float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}

void GameCharacter::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {
    movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void GameCharacter::createAnimationComponent(sf::Texture &texture_sheet) {
    animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void GameCharacter::createHitboxComponent(sf::Sprite &sprite, float offset_x, float offset_y, float width, float height) {
    hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

const sf::Vector2f &GameCharacter::getPosition() const {
    if(hitboxComponent)
        return hitboxComponent->getPosition();
    return sprite.getPosition();
}

const sf::Vector2f GameCharacter::getSpritePosition() const {

    return sprite.getPosition();
}

const sf::Vector2f GameCharacter::getCenter() const {
    if(hitboxComponent)
        return hitboxComponent->getPosition() +
        sf::Vector2f(
                hitboxComponent->getGlobalBounds().width / 2.f,
                hitboxComponent->getGlobalBounds().height / 2
                );
    return
          sprite.getPosition() +
            sf::Vector2f(
                    sprite.getGlobalBounds().width / 2.f,
                    sprite.getGlobalBounds().height / 2
            );
}

const sf::Vector2f GameCharacter::getSpriteCenter() const {
     return sprite.getPosition() +
            sf::Vector2f(
                   sprite.getGlobalBounds().width / 2.f,
                   sprite.getGlobalBounds().height / 2
            );;
}


const sf::FloatRect GameCharacter::getGlobalBounds() const {
    if(hitboxComponent)
        return hitboxComponent->getGlobalBounds();
    return sprite.getGlobalBounds();
}

void GameCharacter::stopVelocity() {
    if(movementComponent)
        movementComponent->stopVelocity();
}

void GameCharacter::stopVelocityX() {
    if(movementComponent)
        movementComponent->stopVelocityX();
}

void GameCharacter::stopVelocityY() {
    if(movementComponent)
        movementComponent->stopVelocityY();
}

const sf::Vector2i GameCharacter::getGridPosition(const int gridSizeI) const {
    if(hitboxComponent)
        return sf::Vector2i(
                static_cast<int>(hitboxComponent->getPosition().x) / gridSizeI,
                static_cast<int>(hitboxComponent->getPosition().y) / gridSizeI
                );
    return sf::Vector2i(
            static_cast<int>(sprite.getPosition().x) / gridSizeI,
            static_cast<int>(sprite.getPosition().y) / gridSizeI
            );
}

const sf::FloatRect GameCharacter::getNextPositionBounds(const float& dt) const {
    if(hitboxComponent && movementComponent)
        return hitboxComponent->getNextPosition(movementComponent->getVelocity() * dt);
    return sf::FloatRect(-1.f, -1.f, -1.f, -1.f);
}

void GameCharacter::createAttributeComponent(const unsigned level) {
    attributeComponent = new AttributeComponent(level);
}

void GameCharacter::createSkillComponent() {

    skillComponent = new SkillComponent();
}

void GameCharacter::createAIComponent() {


}

MovementComponent *GameCharacter::getMovementComponent() {

    return movementComponent;
}

AnimationComponent *GameCharacter::getAnimationComponent() {

    return animationComponent;
}

AttributeComponent *GameCharacter::getAttributeComponent() {

    return attributeComponent;
}

SkillComponent *GameCharacter::getSkillComponent() {

    return skillComponent;
}

const float GameCharacter::getDistance(const GameCharacter& gameCharacter) const {
    return sqrt(pow(getCenter().x - gameCharacter.getCenter().x, 2) + pow(getCenter().y - gameCharacter.getCenter().y, 2));
}

const float GameCharacter::getSpriteDistance(const GameCharacter& gameCharacter) const {
    return sqrt(pow(getSpriteCenter().x - gameCharacter.getSpriteCenter().x, 2) + pow(getSpriteCenter().y - gameCharacter.getSpriteCenter().y, 2));
}




