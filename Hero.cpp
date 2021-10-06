//
// Created by alpacox on 05/03/21.
//

#include "Hero.h"

Hero::Hero(float x, float y, sf::Texture& texture_sheet) {

    this->initVariables();

    this->setPosition(x, y);

    this->createHitboxComponent(this->sprite, 0.f, 17.f, 32.f, 32.f);
    this->createMovementComponent(300.f, 15.f, 5.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 3, 0, 48, 48);
    this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 1, 5, 1, 48, 48);

}

Hero::~Hero() {

}

void Hero::initVariables() {

}

void Hero::initComponents() {

}

void Hero::update(const float &dt) {
    this->movementComponent->update(dt);

    if(this->movementComponent->getState(IDLE))
       this->animationComponent->play("IDLE_RIGHT", dt);
    else if (this->movementComponent->getState(MOVING_RIGHT))
        this->animationComponent->play("WALK_RIGHT", dt);

    this->hitboxComponent->update();
}

/*
Hero::Hero(string n, int maxHP, int ac, int str, int intel, int dex): GameCharacter(maxHP, ac, str, intel, dex) {


    name = n;
    level =1;
    exp = 30; // Test, di norma sarebbe 0
    expNext = 3;
    statsPoints = 0;

    posX = 1;
    posY = 1;

}


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

