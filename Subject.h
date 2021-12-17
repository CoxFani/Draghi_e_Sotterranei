//
// Created by alpacox on 16/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_SUBJECT_H
#define DRAGHI_E_SOTTERRANEI_SUBJECT_H

#include "Observer.h"

class Subject
{
public:
    Subject() = default;
    virtual ~Subject() = default;

    virtual void subscribe(Observer* obs) = 0;
    virtual void unsubscribe(Observer* obs) = 0;

    virtual void notify() = 0;
};

#endif //DRAGHI_E_SOTTERRANEI_SUBJECT_H
