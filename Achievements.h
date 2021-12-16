//
// Created by alpacox on 15/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
#define DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H

#include "Observer.h"


class Achievements
        : public Observer {

    void onNotify(const GameCharacter &gameCharacter, Events event) override;

private:
    void unlock(Achievements achievement);

};

#endif //DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
