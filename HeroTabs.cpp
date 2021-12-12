//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "HeroTabs.h"

HeroTabs::HeroTabs(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: vm(vm), font(font), hero(hero){

    this->initTabs();
    this->initKeyTime();
}

HeroTabs::~HeroTabs() {

}

void HeroTabs::initTabs() {

    this->tabs.push_back(new CharacterTab(vm, font, hero));

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
    // controlla se le Le Tabs sono aperte o chiuse

    bool open = false;
    for(size_t i = 0; i < this->tabs.size() && !open; i++){

        if(this->tabs[i]->getOpen())
            open = true;
    }
    return open;
}

void HeroTabs::toggleTab(const int tab_index) {

    if(tab_index >= 0 || tab_index < this->tabs.size())
        this->tabs[tab_index]->toggle();

}

void HeroTabs::update() {

    for(size_t i = 0; i < this->tabs.size(); i++){

        if(this->tabs[i]->getOpen())
            this->tabs[i]->update();
    }
}

void HeroTabs::render(sf::RenderTarget &target) {

    for(size_t i = 0; i < this->tabs.size(); i++){

        if(this->tabs[i]->getOpen())
            this->tabs[i]->render(target);
    }
}