//
// Created by gabriele on 23/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_OBSERVER_H
#define DRAGHI_E_SOTTERRANEI_OBSERVER_H

class Observer {

public:
    virtual ~Observer() {}

    virtual void update() = 0; //TODO

    virtual void attach() = 0; //TODO
    virtual void detach() = 0; //TODO
};

#endif //DRAGHI_E_SOTTERRANEI_OBSERVER_H
