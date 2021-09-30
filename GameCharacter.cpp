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
    delete this->sprite;


}

void GameCharacter::move(const float& dt, const float dir_x, const float dir_y) {
    if(this->sprite) {
        this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
    }
}

void GameCharacter::update(const float &dt) {

}

void GameCharacter::render(sf::RenderTarget* target) {
    if(this->sprite) {
        target->draw(*this->sprite);
    }
}

void GameCharacter::createSprite(sf::Texture *texture) {
    this->texture = texture;
    this->sprite->setTexture(*this->texture);

}

void GameCharacter::initVariables() {
    this->texture = nullptr;
    this->sprite = nullptr;
    this->movementSpeed = 100.f;

}
