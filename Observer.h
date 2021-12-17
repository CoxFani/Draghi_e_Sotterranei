//
// Created by alpacox on 15/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_OBSERVER_H
#define DRAGHI_E_SOTTERRANEI_OBSERVER_H

#include "GameCharacter.h"

enum Events {KILLER = 0, SERIAL_KILLER, BONK, STYLISH, GOTTA_KILL_EM_ALL, ANIMAL_ACTIVIST, MUMMY_LORD, KING_SCORPION, WHATCHOO_WANNA_DO_TONIGHT, I_AM_SURROUNDED_BY_IDIOTS, SNAKE_SNAAAAKE, BRAAAINS, FAT_MAN, HUMAN_CENTIPEDE, ANTI_TANK};
/**
 * Kill 1 Enemy
 * Kill all Enemies
 * Collide with wall
 * Change your clothes
 * Kill at least one Enemy for each type
 * Extinguish all animals
 * Kill all mummies
 * Kill all scorpions
 * Kill all vultures
 * Kill all hyenas
 * Kill all snakes
 * Kill all deceased
 * Kill all big bloated
 * Kill all centipedes
 * Kill all battle turtles
 * **/

class Observer {
public:
    Observer() = default;

    virtual ~Observer() = default;
    virtual void onNotify(const GameCharacter& gameCharacter, Events event) = 0;

    virtual void update() = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};

#endif //DRAGHI_E_SOTTERRANEI_OBSERVER_H
