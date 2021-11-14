//
// Created by alpacox on 14/11/21.
//

#include "precompiler.h"
#include "HeroGUI.h"

HeroGUI::HeroGUI(Hero* hero) {

    this->hero = hero;

    this->initFont();

    this->initHPBar();

}

HeroGUI::~HeroGUI() {

}

void HeroGUI::initFont() {

    this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf");
}

void HeroGUI::initHPBar() {

    float width = 300.f;
    float height = 30.f;
    float x = 20.f;
    float y = 20.f;

    this->hpBarBack.setSize(sf::Vector2f(width, height));
    this->hpBarBack.setFillColor(sf::Color(0, 0, 0, 200));
    this->hpBarBack.setOutlineThickness(2);
    this->hpBarBack.setOutlineColor(sf::Color::White);
    this->hpBarBack.setPosition(x, y);

    this->hpBarInner.setSize(sf::Vector2f(width, height));
    this->hpBarInner.setFillColor(sf::Color(250, 20, 20, 200));
    this->hpBarInner.setPosition(this->hpBarBack.getPosition());

}

void HeroGUI::update(const float &dt) {

}

void HeroGUI::updateHPBar() {

}

void HeroGUI::render(sf::RenderTarget &target) {

    this->renderHPBar(target);
}

void HeroGUI::renderHPBar(sf::RenderTarget &target) {

    target.draw(this->hpBarBack);
    target.draw(this->hpBarInner);
}








