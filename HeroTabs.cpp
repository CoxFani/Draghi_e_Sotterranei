//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "HeroTabs.h"

HeroTabs::HeroTabs(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: vm(vm), font(font), hero(hero){

    initTabs();
    initKeyTime();
}

HeroTabs::~HeroTabs() {

}

void HeroTabs::initTabs() {

    tabs.push_back(new CharacterTab(vm, font, hero));

}

void HeroTabs::initKeyTime() {

    keyTimeMax = 0.3f;
    keyTimer.restart();
}

const bool HeroTabs::getKeyTime() {

    if(keyTimer.getElapsedTime().asSeconds() >= keyTimeMax){
        keyTimer.restart();
        return true;
    }
    return false;
}

const bool HeroTabs::tabsOpen() {
    // controlla se le Le Tabs sono aperte o chiuse

    bool open = false;
    for(size_t i = 0; i < tabs.size() && !open; i++){

        if(tabs[i]->getOpen())
            open = true;
    }
    return open;
}

void HeroTabs::toggleTab(const int tab_index) {

    if(tab_index >= 0 || tab_index < tabs.size())
        tabs[tab_index]->toggle();

}

void HeroTabs::update() {

    for(size_t i = 0; i < tabs.size(); i++){

        if(!tabs[i]->getOpen())
            tabs[i]->update();
    }
}

void HeroTabs::render(sf::RenderTarget &target) {

    for(size_t i = 0; i < tabs.size(); i++){

        if(!tabs[i]->getOpen())
            tabs[i]->render(target);
    }
}