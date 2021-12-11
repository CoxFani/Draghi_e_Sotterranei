//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "CharacterTab.h"

CharacterTab::CharacterTab(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: Tab(vm, font, hero, true) {
    this->back.setFillColor(sf::Color(50, 50, 50, 180));
    this->back.setSize(sf::Vector2f(gui::p2pX(15.f, this->vm), gui::p2pX(20.f, this->vm)));
    this->back.setPosition(20, 150);

    this->infoText.setFont(this->font);
    this->infoText.setCharacterSize(gui::calcCharSize(this->vm, 50));
    this->infoText.setFillColor(sf::Color::White);
    this->infoText.setPosition(this->back.getPosition().x + 20.f, this->back.getPosition().y + 20.f);
}

CharacterTab::~CharacterTab() {

}

void CharacterTab::update() {
    if(!this->hidden){

    }
}

void CharacterTab::render(sf::RenderTarget &target) {
    if(!this->hidden){
        target.draw(back);
        target.draw(infoText);
    }
}


