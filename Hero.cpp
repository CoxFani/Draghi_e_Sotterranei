//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Hero.h"

Hero::Hero(float x, float y, sf::Texture& texture_sheet) {

    this->initVariables();

    this->setPosition(x, y);

    this->createHitboxComponent(this->sprite, 0.f, 17.f, 32.f, 32.f);
    this->createMovementComponent(350.f, 15.f, 5.f);
    this->createAnimationComponent(texture_sheet);

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

Hero::~Hero() {

}

void Hero::initVariables() {
    this->attacking = false;

}

void Hero::initComponents() {

}

void Hero::update(const float &dt) {
    this->movementComponent->update(dt);

    this->updateAttack();

    this->updateAnimation(dt);

    this->hitboxComponent->update();
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

/*



const string Hero::toString() {

    stringstream ss;

    ss << "Name: " << this -> name << "\n"
       << "Health: " << this -> health << "/" << this -> maxHealth <<"\n"
       << "Armor Class: " << this -> armorClass << "\n"
       << "Strength: " << this -> strength << "\n"
       << "Dexterity: " << this -> dexterity << "\n"
       << "Intelligence: " << this -> intelligence << "\n"
       <<"\n";

    return ss.str();

}

bool Hero::canLevelUp() {

    if (this -> exp >= this ->expNext){

        this -> level++;
        this -> exp -= this -> expNext;
        this -> expNext = (this -> level *3);
        this -> statsPoints++;

        return true;
    }
    return false;
}

int Hero::getChoice() {
    int choice = 0;

    cout << "Enter choice: ";
    cin >> choice;

    return choice;

}

void Hero::levelUpStats() {

    cout << "which stat do you want to level up?" << "\n"
         << " (0) Max HP: " << this -> maxHealth << " -> " << this -> maxHealth + this -> statsPoints * 5 << "\n"
         << " (1) Strength: " << this -> strength << " -> " << this -> strength + this -> statsPoints * 2 << "\n"
         << " (2) Dexterity: " << this -> dexterity << " -> " << this -> dexterity + this -> statsPoints * 2 << "\n"
         << " (3) Intelligence: " << this -> intelligence << " -> " << this -> intelligence + this -> statsPoints * 2 << "\n";

    switch (getChoice()) {
        case 0:
            this -> maxHealth += this -> statsPoints * 5;
            this -> statsPoints--;
            cout << "Max Health increased!" << "\n";
            break;

        case 1:
            this -> strength += this -> statsPoints * 2;
            this -> statsPoints--;
            cout << "Strength increased!" << "\n";
            break;

        case 2:
            this -> dexterity += this -> statsPoints * 2;
            this -> statsPoints--;
            cout << "Dexterity increased!" << "\n";
            break;

        case 3:
            this -> intelligence += this -> statsPoints * 2;
            this -> statsPoints--;
            cout << "Intelligence increased!" << "\n";
            break;

        default:
            cout << setw(7) << "---- ERROR 404: STAT NOT FOUD, try again! ----" << "\n";
            break;

    }

}
*/

