//
// Created by alpacox on 02/12/21.
//
#include "precompiler.h"
#include "Mummy.h"

Mummy::Mummy(float x, float y, sf::Texture &texture_sheet)
      : Enemy() {

    this->initVariables();

    this->createHitboxComponent(this->sprite, 15.f, 15.f, 32.f, 32.f);
    this->createMovementComponent(50.f, 1600.f, 1000.f);
    this->createAnimationComponent(texture_sheet);
    this->createAttributeComponent(1);

    this->setPosition(x, y);
    this->initAnimations();
}

Mummy::~Mummy() {

}

void Mummy::initVariables() {

}


void Mummy::initAnimations() {
    this->animationComponent->addAnimation("IDLE", 11.f, 0, 0, 3, 0, 48, 48);
    this->animationComponent->addAnimation("WALK", 8.f, 0, 1, 5, 1, 48, 48);
    this->animationComponent->addAnimation("ATTACK", 6.f, 0, 2, 5, 2, 48, 48);
    this->animationComponent->addAnimation("DEATH", 12.f, 0, 3, 5, 3, 48, 48);
    this->animationComponent->addAnimation("HURT", 7.f, 0, 4, 1, 4, 48, 48);
}

void Mummy::updateAnimation(const float &dt) {
    if(this->movementComponent->getState(IDLE))
        this->animationComponent->play("IDLE", dt);
    else if (this->movementComponent->getState(MOVING_RIGHT)){
        if(this->sprite.getScale().x < 0.f){
            this->sprite.setOrigin(0.f, 0.f);
            this->sprite.setScale(1.f, 1.f);
        }
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_LEFT)){
        if(this->sprite.getScale().x > 0.f) {
            this->sprite.setOrigin(30.f, 0.f);
            this->sprite.setScale(-1.f, 1.f);
        }
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_UP)){
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_DOWN)){
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
}

void Mummy::update(const float &dt, sf::Vector2f& mouse_pos_view) {
    this->movementComponent->update(dt);
    //this->updateAttack();
    this->updateAnimation(dt);
    this->hitboxComponent->update();
}

void Mummy::render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox) {
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);

        target.draw(this->sprite, shader);
    }
    else{
        target.draw(this->sprite);
    }

    if(show_hitbox)
        this->hitboxComponent->render(target);
}

void Mummy::takeDamage(const int damage) {
    this->attributeComponent->loseHP(damage);
}
