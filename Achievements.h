//
// Created by alpacox on 15/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
#define DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H

#include "Observer.h"
#include "GameManager.h"


class Achievements
        : public Observer {

public:
    Achievements() = default;
    explicit Achievements(GameManager * subject);
    virtual ~Achievements();

    //void onNotify(const GameCharacter &gameCharacter, Events event) override;

    void unlock(Achievements event);

private:
    GameManager * subject;
    int event;

    int kills;

    sf::Font font;

    sf::Text text;

    virtual void update();
    virtual void attach();
    virtual void detach();

};

#endif //DRAGHI_E_SOTTERRANEI_ACHIEVEMENTS_H
