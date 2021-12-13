//
// Created by alpacox on 13/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_AICOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_AICOMPONENT_H

#include "GameCharacter.h"
#include "AIFollow.h"

class AIComponent {
public:
    AIComponent(GameCharacter& self, GameCharacter& gameCharacter);
    ~AIComponent();

private:
    GameCharacter& gameCharacter;
    GameCharacter& self;

    void update(const float& dt);

};


#endif //DRAGHI_E_SOTTERRANEI_AICOMPONENT_H
