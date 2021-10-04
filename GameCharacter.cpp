//
// Created by alpacox on 05/03/21.
//

#include "GameCharacter.h"
#include "Dice.h"

#include <iostream>

/* POINTZERO
using namespace std;

GameCharacter::GameCharacter(int maxHp, int ac, int str, int intel, int dex) {

    maxHealth = maxHp;
    health = maxHp;
    armorClass = ac;
    strength = str;
    intelligence = intel;
    dexterity = dex;
    weapon= nullptr;

}

GameCharacter::~GameCharacter() {
    if (weapon != nullptr)
        delete weapon;
}

bool GameCharacter::isLegalFight(const GameCharacter &enemy, Weapon &wpn) const {
    //TODO distinguere se il combattimento è legale a seconda se viene usata un'arma a distanza o corpo a corpo e a seconda della direzione in cui è rivolto il GameCharachter
}

void GameCharacter::basicFight(GameCharacter &enemy) {
    int hit = 1;
    Dice d20(20);
    int hitChance = 0;
    if (weapon) {
        hit = weapon->use();
        if (weapon->isMagic())
            hitChance += 1;
    }

     hitChance += d20.roll(1);
    if(hitChance >= armorClass){
        if(hitChance==20) {
            hit *= 2;
            //TODO "Critical Hit!"
        }
        health -= hit;
    } //else TODO"MISS"

}

int GameCharacter::distance(const GameCharacter &h, const GameCharacter &e) {
    int distance = abs(h.posX - e.posX) + abs(h.posY - e.posY);
    return distance;
}

const string GameCharacter::toString() {

    stringstream ss;

    ss //<< "Name: " << this -> name << "\n"
            << "Health: " << this -> health << "/" << this -> maxHealth <<"\n"
            << "Armor Class: " << this -> armorClass << "\n"
            << "Strength: " << this -> strength << "\n"
            << "Dexterity: " << this -> dexterity << "\n"
            << "Intelligence: " << this -> intelligence << "\n"
            <<"\n";

    return ss.str();

}
*/
GameCharacter::GameCharacter() {
    this->initVariables();
}

GameCharacter::~GameCharacter() {

    delete this->movementComponent;
    delete this->animationComponent;

}

void GameCharacter::move(const float dir_x, const float dir_y,const float& dt) {
    if(this->movementComponent) {
        this->movementComponent->move(dir_x, dir_y, dt);
    }
}

void GameCharacter::update(const float &dt) {

}

void GameCharacter::render(sf::RenderTarget* target) {

        target->draw(this->sprite);

}

void GameCharacter::setTexture(sf::Texture& texture) {
    this->sprite.setTexture(texture);

}

void GameCharacter::initVariables() {

    this->movementComponent = nullptr;
}

void GameCharacter::setPosition(const float x, const float y) {

        this->sprite.setPosition(x, y);

}

void GameCharacter::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) {

    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);

}

void GameCharacter::createAnimationComponent(sf::Texture &texture_sheet) {

    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}
