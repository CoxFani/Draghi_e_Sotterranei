//
// Created by alpacox on 14/11/21.
//

#include "precompiler.h"
#include "HeroGUI.h"

HeroGUI::HeroGUI(Hero* hero, sf::VideoMode& vm)
: vm(vm){
    this->hero = hero;

    this->initFont();
    this->initLevelBar();
    this->initEXPBar();
    this->initHPBar();
}

HeroGUI::~HeroGUI() {

}

void HeroGUI::initFont() {
    this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf");
}

void HeroGUI::initLevelBar() {
    float width = gui::p2pX(2.34f, this->vm);
    float height = gui::p2pY(4.16f, this->vm);
    float x = gui::p2pX(1.56f, this->vm);
    float y = gui::p2pY(2.77f, this->vm);

    this->levelBarBack.setSize(sf::Vector2f(width, height));
    this->levelBarBack.setFillColor(sf::Color(50, 50, 50, 200));
    this->levelBarBack.setPosition(x, y);

    this->levelBarText.setFont(this->font);
    this->levelBarText.setCharacterSize(gui::calcCharSize(this->vm, 90));
    this->levelBarText.setPosition(
            this->levelBarBack.getPosition().x + gui::p2pX(0.78f, this->vm),
            this->levelBarBack.getPosition().y + gui::p2pY(0.69f, this->vm)
            );
}

void HeroGUI::initEXPBar() {
    float width = gui::p2pX(15.6f, this->vm);
    float height = gui::p2pY(2.77f, this->vm);
    float x = gui::p2pX(1.56f, this->vm);
    float y = gui::p2pY(6.94, this->vm);

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
    this->expBarText.setCharacterSize(gui::calcCharSize(this->vm, 130));
    this->expBarText.setPosition(
            this->expBarInner.getPosition().x + gui::p2pX(0.78f, this->vm),
            this->expBarInner.getPosition().y + gui::p2pY(0.69f, this->vm)
            );
}

void HeroGUI::initHPBar() {
    float width = gui::p2pX(15.6f, this->vm);
    float height = gui::p2pY(4.16f, this->vm);
    float x = gui::p2pX(1.56f, this->vm);
    float y = gui::p2pY(12.5f, this->vm);

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
    this->hpBarText.setCharacterSize(gui::calcCharSize(this->vm, 85));
    this->hpBarText.setPosition(
            this->hpBarInner.getPosition().x + gui::p2pX(0.78f, this->vm),
            this->hpBarInner.getPosition().y + gui::p2pY(0.69f, this->vm)
            );
}

void HeroGUI::updateLevelBar() {
    this->levelBarString = std::to_string(this->hero->getAttributeComponent()->level);
    this->levelBarText.setString(this->levelBarString);
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
    this->updateLevelBar();
    this->updateEXPBar();
    this->updateHPBar();
}

void HeroGUI::renderLevelBar(sf::RenderTarget &target) {
    target.draw(this->levelBarBack);
    target.draw(this->levelBarText);
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
    this->renderLevelBar(target);
    this->renderEXPBar(target);
    this->renderHPBar(target);
}













