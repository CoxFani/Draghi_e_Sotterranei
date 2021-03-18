//
// Created by alpacox on 05/03/21.
//

#include "GameCharacter.h"
#include "Dice.h"

#include <iostream>

using namespace std;

GameCharacter::GameCharacter(int hp, int ac, int str, int intel, int dex) : health(hp), armorClass(ac),strenght(str), intelligence(intel), dexterity(dex), posX(0), posY(0), weapon(
        nullptr){}

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

