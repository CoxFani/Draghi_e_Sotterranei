//
// Created by alpacox on 14/11/21.
//

#include "precompiler.h"
#include "HeroGUI.h"

HeroGUI::HeroGUI(Hero* hero) {
    this->hero = hero;

    this->initFont();

    this->initEXPBar();
    this->initHPBar();
}

HeroGUI::~HeroGUI() {

}

void HeroGUI::initFont() {
    this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf");
}

void HeroGUI::initEXPBar() {

    float width = 200.f;
    float height = 30.f;
    float x = 20.f;
    float y = 80.f;

    this->expBarMaxWidth = width;

    this->expBarBack.setSize(sf::Vector2f(width, height));
    this->expBarBack.setFillColor(sf::Color(0, 0, 0, 200));
    this->expBarBack.setOutlineThickness(2);
    this->expBarBack.setOutlineColor(sf::Color::White);
    this->expBarBack.setPosition(x, y);

    this->expBarInner.setSize(sf::Vector2f(width, height));
    this->expBarInner.setFillColor(sf::Color(20, 20, 250, 200));
    this->expBarInner.setPosition(this->expBarBack.getPosition());

    this->expBarText.setFont(this->font);
    this->expBarText.setCharacterSize(25);
    this->expBarText.setPosition(this->expBarInner.getPosition().x + 10.f, this->expBarInner.getPosition().y - 5.f);

}

void HeroGUI::initHPBar() {
    float width = 300.f;
    float height = 30.f;
    float x = 20.f;
    float y = 20.f;

    this->hpBarMaxWidth = width;

    this->hpBarBack.setSize(sf::Vector2f(width, height));
    this->hpBarBack.setFillColor(sf::Color(0, 0, 0, 200));
    this->hpBarBack.setOutlineThickness(2);
    this->hpBarBack.setOutlineColor(sf::Color::White);
    this->hpBarBack.setPosition(x, y);

    this->hpBarInner.setSize(sf::Vector2f(width, height));
    this->hpBarInner.setFillColor(sf::Color(250, 20, 20, 200));
    this->hpBarInner.setPosition(this->hpBarBack.getPosition());

    this->hpBarText.setFont(this->font);
    this->hpBarText.setCharacterSize(25);
    this->hpBarText.setPosition(this->hpBarInner.getPosition().x + 10.f, this->hpBarInner.getPosition().y - 5.f);

}

void HeroGUI::updateEXPBar() {
    float percent = static_cast<float>(this->hero->getAttributeComponent()->exp) / static_cast<float>(this->hero->getAttributeComponent()->expNext);

    this->expBarInner.setSize(sf::Vector2f(static_cast<float>(std::floor(this->expBarMaxWidth * percent)), this->expBarInner.getSize().y));

    this->expBarString = std::to_string(this->hero->getAttributeComponent()->exp) + "/" + std::to_string(this->hero->getAttributeComponent()->expNext);
    this->expBarText.setString(this->expBarString);
}

void HeroGUI::updateHPBar() {
    float percent = static_cast<float>(this->hero->getAttributeComponent()->hp) / static_cast<float>(this->hero->getAttributeComponent()->hpMax);

    this->hpBarInner.setSize(sf::Vector2f(static_cast<float>(std::floor(this->hpBarMaxWidth * percent)), this->hpBarInner.getSize().y));

    this->hpBarString = std::to_string(this->hero->getAttributeComponent()->hp) + "/" + std::to_string(this->hero->getAttributeComponent()->hpMax);
    this->hpBarText.setString(this->hpBarString);
}

void HeroGUI::update(const float &dt) {
    this->updateEXPBar();
    this->updateHPBar();
}

void HeroGUI::renderEXPBar(sf::RenderTarget &target) {
    target.draw(this->expBarBack);
    target.draw(this->expBarInner);
    target.draw(this->expBarText);
}

void HeroGUI::renderHPBar(sf::RenderTarget &target) {
    target.draw(this->hpBarBack);
    target.draw(this->hpBarInner);
    target.draw(this->hpBarText);
}

void HeroGUI::render(sf::RenderTarget &target) {
    this->renderEXPBar(target);
    this->renderHPBar(target);
}













