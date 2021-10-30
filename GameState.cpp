//
// Created by alpacox on 26/03/21.
//

#include "precompiler.h"
#include "GameState.h"

class PauseMenu;
class Hero;
class TileMap;


GameState::GameState(StateData* state_data)
    : State(state_data)
{
    this->initDeferredRender();
    this->initView();
    this->initKeybinds();
    this->initFonts();
    this->initTextures();
    this->initPausedMenu();

    this->initHeroes();
    this->initTileMap();
}

GameState::~GameState() {
    delete this->pmenu;
    delete this->hero;
    delete this->tileMap;
}

void GameState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    this->renderTexture.clear();

    this->renderTexture.setView(this->view);
    this->tileMap->render(this->renderTexture, this->hero);

    this->hero->render(this->renderTexture);

    if(this->paused){
        this->renderTexture.setView(this->renderTexture.getDefaultView());
        this->pmenu->render(this->renderTexture);
    }

    this->renderTexture.display();
    this->renderSprite.setTexture(this->renderTexture.getTexture());
    target->draw(this->renderSprite);
}



void GameState::updateHeroInput(const float &dt) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->hero->move(-1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->hero->move(1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->hero->move(0.f, -1.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->hero->move(0.f, 1.f, dt);

}

void GameState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime()){
        if(!this->paused)
            this->pauseState();
        else
            this->unpauseState();
    }
}

void GameState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateInput(dt);
    this->updateKeyTime(dt);

    if(!this->paused) {
        this->updateView(dt);
        this->updateHeroInput(dt);
        this->hero->update(dt);
        this->updateTileMap(dt);
    }
    else{
        this->pmenu->update(this->mousePosWindow);
        this->updatePauseMenuButtons();
    }
}

void GameState::initKeybinds() {

    std::ifstream ifs("../Config/gamestate_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
/*
    this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    */
}

void GameState::initFonts() {

    if(!this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }

}

void GameState::initTextures() {

    if (!this->textures["HERO_SHEET"].loadFromFile("../Resources/Images/Images/Sprites/Hero/Woodcutter_animations.png")){

        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HERO_TEXTURE";
    };

}

void GameState::initHeroes() {

    this->hero = new Hero(0, 0, this->textures["HERO_SHEET"]);

}

void GameState::initPausedMenu() {
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 450.f, "Quit");
}

void GameState::updatePauseMenuButtons() {
    if(this->pmenu->isButtonPressed("QUIT"))
        this->endState();
}

void GameState::initTileMap() {
//TODO cambiare dimensioni mappa
    this->tileMap = new TileMap(this->stateData->gridSize, 10, 10, "../Resources/Images/Tiles/tilesheet1.png");
    this->tileMap->loadFromFile("../save_files.txt");
}

void GameState::initView() {

    this->view.setSize(
            sf::Vector2f(
                    this->stateData->gfxSettings->resolution.width,
                    this->stateData->gfxSettings->resolution.height
            )
    );

    this->view.setCenter(
            sf::Vector2f(
                    this->stateData->gfxSettings->resolution.width / 2.f,
                    this->stateData->gfxSettings->resolution.height / 2.f
            )
    );

}

void GameState::updateView(const float &dt) {
    this->view.setCenter(std::floor(this->hero->getPosition().x), std::floor(this->hero->getPosition().y));
}

void GameState::initDeferredRender() {
    this->renderTexture.create(this->stateData->gfxSettings->resolution.width, this->stateData->gfxSettings->resolution.height);
    this->renderSprite.setTexture(this->renderTexture.getTexture());
    this->renderSprite.setTextureRect(sf::IntRect(0, 0, this->stateData->gfxSettings->resolution.width, this->stateData->gfxSettings->resolution.height));
}

void GameState::updateTileMap(const float &dt) {

    this->tileMap->update();
    this->tileMap->updateCollision(this->hero, dt);
}
