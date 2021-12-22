//
// Created by gabriele on 21/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMEMANAGER_H
#define DRAGHI_E_SOTTERRANEI_GAMEMANAGER_H

#include "Subject.h"

class GameManager
        : public Subject {

public:
    GameManager();
    virtual ~GameManager();

    virtual void subscribe(Observer* obs);
    virtual void unsubscribe(Observer* obs);
    virtual void notify();

private:
    std::list<Observer*> observers;

};


#endif //DRAGHI_E_SOTTERRANEI_GAMEMANAGER_H
