//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Hero.h"

Hero::Hero(float x, float y, sf::Texture& texture_sheet) {
    this->initVariables();


    this->createHitboxComponent(this->sprite, 7.f, 20.f, 20.f, 20.f);
    this->createMovementComponent(140.f, 1500.f, 500.f);
    this->createAnimationComponent(texture_sheet);
    this->createAttributeComponent(1);
    this->createSkillComponent();

    this->setPosition(x, y);
    this->initAnimations();

    this->initInventory();

}

Hero::~Hero() {
    delete this->inventory;

    delete this->weapon;

}

void Hero::initVariables() {

    this->initAttack = false;
    this->attacking = false;
    this->weapon = new Sword(1, 2, 5, 65, 20, "../Resources/Images/Sprites/Weapons/weapon.png");
    this->weapon->generate(1, 3);
    this->inventory = new Inventory(100);

    this->damageTimerMax = 1000;
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

void Hero::initInventory() {



}

AttributeComponent *Hero::getAttributeComponent() {
    return this->attributeComponent;
}

Weapon *Hero::getWeapon() const {
    return this->weapon;
}

const std::string Hero::toStringCharacterTab() const {
    std::stringstream ss;
    const AttributeComponent* ac = this->attributeComponent;
    const Weapon* w = this->weapon;
    ss << "Level: " << ac->level << "\n"
       << "Experience: " << ac->exp <<"\n"
       << "Exp next: " << ac->expNext <<"\n"
       << "Weapon Level: " << w->getLevel() << "\n"
       << "Weapon Type: " << w->getType() << "\n"
       << "Weapon Value: " << w->getValue() << "\n"
       << "Weapon Range: " << w->getRange() << "\n"
       << "Weapon Damage Min: " << w->getDamageMin() + this->attributeComponent->damageMin << " (" << this->attributeComponent->damageMin << ") " << "\n"
       << "Weapon Damage Max: " << w->getDamageMax() + this->attributeComponent->damageMax << " (" << this->attributeComponent->damageMax << ") " << "\n";
    return ss.str();
}

const bool &Hero::getInitAttack() const {

    return this->initAttack;
}

void Hero::setInitAttack(const bool initAttack) {

    this->initAttack = initAttack;
}

const bool Hero::getDamageTimer() {

    if(this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax){
        this->damageTimer.restart();
        return true;
    }
    else
        return false;
}

const unsigned Hero::getDamage() const {
    return rand() % (
            (this->attributeComponent->damageMax + this->weapon->getDamageMax())
            - (this->attributeComponent->damageMin + this->weapon->getDamageMin()) + 1)
            + (this->attributeComponent->damageMin + this->weapon->getDamageMin());
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

    if(this->damageTimer.getElapsedTime().asMilliseconds() <= this->damageTimerMax){
        //this->animationComponent->play("HURT", dt, true);
        this->sprite.setColor(sf::Color::Red);
    }
    else
        this->sprite.setColor(sf::Color::White);
}

void Hero::update(const float &dt, sf::Vector2f& mouse_pos_view, const sf::View& view) {
    this->movementComponent->update(dt);
    this->updateAnimation(dt);
    this->hitboxComponent->update();
    this->weapon->update(mouse_pos_view, sf::Vector2f(this->getSpriteCenter().x, this->getSpriteCenter().y + 5.f));
}

void Hero::render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox) {
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);
        target.draw(this->sprite, shader);

        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);
        this->weapon->render(target, shader);
    }
    else{
        target.draw(this->sprite);
        this->weapon->render(target);
    }

    if(show_hitbox)
        this->hitboxComponent->render(target);
}

void Hero::updateAttack() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->attacking = true;
    }
}