//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "HeroTabs.h"

HeroTabs::HeroTabs(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: vm(vm), font(font), hero(hero),
characterTab(vm, font, hero){

    this->initKeyTime();


}

HeroTabs::~HeroTabs() {

}

void HeroTabs::initKeyTime() {

    this->keyTimeMax = 0.3f;
    this->keyTimer.restart();
}

const bool HeroTabs::getKeyTime() {

    if(this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax){
        this->keyTimer.restart();
        return true;
    }
    return false;
}

const bool HeroTabs::tabsOpen() {
    return this->characterTab.getOpen(
            );
}

void HeroTabs::update() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->getKeyTime()){

        if(this->characterTab.getHidden())
            this->characterTab.show();
        else
            this->characterTab.hide();
    }
}

void HeroTabs::render(sf::RenderTarget &target) {

    this->characterTab.render(target);

}


