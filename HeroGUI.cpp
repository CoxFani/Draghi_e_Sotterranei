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
    this->initHeroTabs(vm, font, *hero);
}

HeroGUI::~HeroGUI() {
    delete this->hpBar;
    delete this->expBar;
    delete this->heroTabs;
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
    this->levelBarText.setCharacterSize(gui::calcCharSize(this->vm, 75));
    this->levelBarText.setPosition(
            this->levelBarBack.getPosition().x + gui::p2pX(0.78f, this->vm),
            this->levelBarBack.getPosition().y - gui::p2pY(0.69f, this->vm)
            );
}

void HeroGUI::initEXPBar() {
    this->expBar = new gui::ProgressBar(1.56f, 6.94, 15.6f, 2.77f,
                                       this->hero->getAttributeComponent()->expNext,
                                        sf::Color(20, 20, 250, 200),
                                       this->vm, 100,
                                       &this->font);
}

void HeroGUI::initHPBar() {
    this->hpBar = new gui::ProgressBar(1.56f, 12.5f, 15.6f, 4.16f,
                                       this->hero->getAttributeComponent()->hpMax,
                                       sf::Color(250, 20, 20, 200),
                                       this->vm, 75,
                                       &this->font);
}

void HeroGUI::initHeroTabs(sf::VideoMode& vm, sf::Font &font, Hero& hero) {
    this->heroTabs = new HeroTabs(vm, font, hero);
}

const bool HeroGUI::getsTabsOpen() const {
    return this->heroTabs->tabsOpen();
}

void HeroGUI::updateLevelBar() {
    this->levelBarString = std::to_string(this->hero->getAttributeComponent()->level);
    this->levelBarText.setString(this->levelBarString);
}

void HeroGUI::updateEXPBar() {
    this->expBar->update(this->hero->getAttributeComponent()->exp);
}

void HeroGUI::updateHPBar() {
    this->hpBar->update(this->hero->getAttributeComponent()->hp);
}

void HeroGUI::updateHeroTabs() {
    this->heroTabs->update();
}

void HeroGUI::update(const float &dt) {
    this->updateLevelBar();
    this->updateEXPBar();
    this->updateHPBar();
    this->updateHeroTabs();
}


void HeroGUI::renderLevelBar(sf::RenderTarget &target) {
    target.draw(this->levelBarBack);
    target.draw(this->levelBarText);
}

void HeroGUI::renderEXPBar(sf::RenderTarget &target) {
    this->expBar->render(target);
}

void HeroGUI::renderHPBar(sf::RenderTarget &target) {
    this->hpBar->render(target);
}

void HeroGUI::renderHeroTabs(sf::RenderTarget &target) {
    this->heroTabs->render(target);
}

void HeroGUI::render(sf::RenderTarget &target) {
    this->renderLevelBar(target);
    this->renderEXPBar(target);
    this->renderHPBar(target);
    this->renderHeroTabs(target);
}

void HeroGUI::toggleCharacterTab() {

    this->heroTabs->toggleTab(HERO_TABS::CHARACTER_TAB);
}
