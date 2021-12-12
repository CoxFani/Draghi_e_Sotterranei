//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "Tab.h"

Tab::Tab(sf::VideoMode& vm, sf::Font& font, Hero& hero, bool hidden)
: vm(vm), font(font), hero(hero), hidden(hidden) {

}

Tab::~Tab() {

}

const bool &Tab::getHidden() const {

    return this->hidden;
}

const bool &Tab::getOpen() const {

    return this->hidden;
}

void Tab::hide() {

    this->hidden = true;
}

void Tab::show() {

    this->hidden = false;
}

void Tab::toggle() {

    if(this->hidden)
        this->hidden = false;
    else
        this->hidden = true;
}