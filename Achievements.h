//
// Created by alpacox on 15/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
#define DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H

#include "Observer.h"


class Achievements
        : public Observer {

public:

    Achievements() = default;
    //explicit Achievements(RoundManager * subject);
    virtual ~Achievements();

    void onNotify(const GameCharacter &gameCharacter, Events event) override;

private:

    int kills;

    //RoundManager * subject;

    sf::Font font;

    sf::Text text;

    virtual void update();
    virtual void attach();
    virtual void detach();

};

#endif //DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
