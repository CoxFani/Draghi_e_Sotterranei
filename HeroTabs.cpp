//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "HeroTabs.h"

HeroTabs::HeroTabs(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: vm(vm), font(font), hero(hero),
characterTab(vm, font, hero){


}

HeroTabs::~HeroTabs() {

}

void HeroTabs::update() {

}

void HeroTabs::render(sf::RenderTarget *target) {

    this->characterTab.render(target);

}

