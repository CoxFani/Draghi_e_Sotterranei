//
// Created by alpacox on 02/12/21.
//
#include "precompiler.h"
#include "Mummy.h"

Mummy::Mummy(float x, float y, sf::Texture &texture_sheet, EnemySpawnerTile& enemy_spawner_tile, GameCharacter& hero)
      : Enemy(enemy_spawner_tile) {

    this->initVariables();
    initGUI();

    this->createHitboxComponent(this->sprite, 20.f, 15.f, 25.f, 25.f);
    this->createMovementComponent(50.f, 1600.f, 1000.f);
    this->createAnimationComponent(texture_sheet);
    this->createAttributeComponent(1);

    this->generateAttributes(this->attributeComponent->level);

    this->setPosition(x, y);
    this->initAnimations();

    this->follow = new AIFollow(*this, hero);
}

Mummy::~Mummy() {

    delete this->follow;
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

void Mummy::initGUI() {

    this->hpBar.setFillColor(sf::Color::Red);
    this->hpBar.setSize(sf::Vector2f(40.f, 5.f));
    this->hpBar.setPosition(this->sprite.getPosition().x + 12.f , this->sprite.getPosition().y);
}

void Mummy::updateAnimation(const float &dt) {
    if(this->movementComponent->getState(IDLE))
        this->animationComponent->play("IDLE", dt);
    else if (this->movementComponent->getState(MOVING_RIGHT)){
        if(this->sprite.getScale().x > 0.f){ // <
            this->sprite.setOrigin(64.f, 0.f);  // 0, 0
            this->sprite.setScale(-1.f, 1.f); // 1, 1
        }
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_LEFT)){
        if(this->sprite.getScale().x < 0.f) { // >
            this->sprite.setOrigin(0.f, 0.f); // 30, 0
            this->sprite.setScale(1.f, 1.f); // -1, 1
        }
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_UP)){
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    else if(this->movementComponent->getState(MOVING_DOWN)){
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    if(this->damageTimer.getElapsedTime().asMilliseconds() <= this->damageTimerMax){
        //this->animationComponent->play("HURT", dt, true);
        this->sprite.setColor(sf::Color::Red);
    }
    else
        this->sprite.setColor(sf::Color::White);

//TODO animazioni di morte
    if(isDead()){
        this->animationComponent->play("DEATH", dt, true);

    }


}

void Mummy::update(const float &dt, sf::Vector2f& mouse_pos_view, const sf::View& view) {

    Enemy::update(dt, mouse_pos_view, view);
    this->movementComponent->update(dt);

    this->hpBar.setSize(sf::Vector2f(40.f * (static_cast<float>(this->attributeComponent->hp) / this->attributeComponent->hpMax), 5.f));
    this->hpBar.setPosition(this->sprite.getPosition().x + 12.f , this->sprite.getPosition().y); //TEST. DA RIMUOVERE!!!

    //this->updateAttack();
    this->updateAnimation(dt);
    this->hitboxComponent->update();
    this->follow->update(dt);
}

void Mummy::render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox) {
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);

        target.draw(this->sprite, shader);
        target.draw(this->hpBar, shader);
    }
    else{
        target.draw(this->sprite);
        target.draw(this->hpBar);
    }


    if(show_hitbox)
        this->hitboxComponent->render(target);
}

void Mummy::iniAI() {

}


