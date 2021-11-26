//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Hero.h"

Hero::Hero(float x, float y, sf::Texture& texture_sheet) {
    this->initVariables();


    this->createHitboxComponent(this->sprite, 0.f, 17.f, 32.f, 32.f);
    this->createMovementComponent(200.f, 1500.f, 500.f);
    this->createAnimationComponent(texture_sheet);
    this->createAttributeComponent(1);
    this->createSkillComponent();

    this->setPosition(x, y);
    this->initAnimations();



}

Hero::~Hero() {

}

void Hero::initVariables() {
    this->attacking = false;
}

void Hero::initComponents() {

}

void Hero::initAnimations() {

    this->animationComponent->addAnimation("IDLE", 11.f, 0, 0, 3, 0, 48, 48);
    this->animationComponent->addAnimation("WALK", 8.f, 0, 1, 5, 1, 48, 48);
    this->animationComponent->addAnimation("ATTACK1", 6.f, 0, 2, 5, 2, 48, 48);
    this->animationComponent->addAnimation("ATTACK2", 7.f, 0, 3, 5, 3, 48, 48);
    this->animationComponent->addAnimation("ATTACK3", 7.f, 0, 4, 5, 4, 48, 48);
    this->animationComponent->addAnimation("DEATH", 12.f, 0, 5, 5, 5, 48, 48);
    this->animationComponent->addAnimation("HURT", 7.f, 0, 6, 2, 6, 48, 48);
    this->animationComponent->addAnimation("JUMP", 7.f, 0, 7, 5, 7, 48, 48);
    this->animationComponent->addAnimation("RUN", 6.f, 0, 8, 5, 8, 48, 48);
}

AttributeComponent *Hero::getAttributeComponent() {
    return this->attributeComponent;
}

void Hero::loseHP(const int hp) {

    this->attributeComponent->loseHP(hp);
}

void Hero::gainHP(const int hp) {

    this->attributeComponent->gainHP(hp);
}

void Hero::loseEXP(const int exp) {

    this->attributeComponent->loseEXP(exp);
}



void Hero::gainEXP(const int exp) {

    this->attributeComponent->gainEXP(exp);

}

void Hero::updateAttack() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
           this->attacking = true;
    }
}

void Hero::updateAnimation(const float &dt) {
    if(this->attacking){
        /*if(this->sprite.getScale().x > 0.f){
            this->sprite.setOrigin(0.f, 0.f);
        }
        else{
            this->sprite.setOrigin(0.f, 0.f);
        }*/
        if(this->animationComponent->play("ATTACK1", dt, true)){
            this->attacking = false;
        }
    }

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

void Hero::update(const float &dt, sf::Vector2f& mouse_pos_view) {
    this->movementComponent->update(dt);
    this->updateAttack();
    this->updateAnimation(dt);
    this->hitboxComponent->update();
    this->sword.update(mouse_pos_view, this->getCenter());
}

void Hero::render(sf::RenderTarget &target, sf::Shader* shader, const bool show_hitbox) {

    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", this->getCenter());

        target.draw(this->sprite, shader);
        this->sword.render(target, shader);
    }
    else{
        target.draw(this->sprite);
        this->sword.render(target);
    }



    if(show_hitbox)
        this->hitboxComponent->render(target);
}








