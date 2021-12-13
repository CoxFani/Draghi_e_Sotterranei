//
// Created by alpacox on 09/12/21.
//

#include "precompiler.h"
#include "CharacterTab.h"

CharacterTab::CharacterTab(sf::VideoMode& vm, sf::Font& font, Hero& hero)
: Tab(vm, font, hero, true) {
    this->back.setFillColor(sf::Color(30, 30, 30, 200));
    this->back.setSize(sf::Vector2f(gui::p2pX(22.f, this->vm), gui::p2pX(20.f, this->vm)));
    this->back.setPosition(20, 150);

    this->initText();
}

CharacterTab::~CharacterTab() {

}

void CharacterTab::update() {
    if(!this->hidden){
        this->infoText.setString(this->hero.toStringCharacterTab());
    }
}

void CharacterTab::render(sf::RenderTarget &target) {
    if(!this->hidden){
        target.draw(back);
        target.draw(infoText);
    }
}

void CharacterTab::initText() {
    this->infoText.setFont(this->font);
    this->infoText.setCharacterSize(gui::calcCharSize(this->vm, 100));
    this->infoText.setFillColor(sf::Color(200, 200, 200, 240));
    this->infoText.setPosition(this->back.getPosition().x + 20.f, this->back.getPosition().y + 20.f);
    this->infoText.setString(this->hero.toStringCharacterTab());
}


