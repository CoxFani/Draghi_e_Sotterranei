//
// Created by gabriele on 23/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_SUBJECT_H
#define DRAGHI_E_SOTTERRANEI_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyObservers() = 0;
};

#endif //DRAGHI_E_SOTTERRANEI_SUBJECT_H
