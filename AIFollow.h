//
// Created by gabriele on 13/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_AIFOLLOW_H
#define DRAGHI_E_SOTTERRANEI_AIFOLLOW_H

#include "AIOption.h"

class AIFollow : public AIOption {
public:
    AIFollow(GameCharacter &self, GameCharacter &gameCharacter);
    ~AIFollow();

    void update(const float& dt);

};


#endif //DRAGHI_E_SOTTERRANEI_AIFOLLOW_H
