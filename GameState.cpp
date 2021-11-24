//
// Created by alpacox on 26/03/21.
//

#include "precompiler.h"
#include "GameState.h"

class PauseMenu;
class Hero;
class TileMap;


GameState::GameState(StateData* state_data)
    : State(state_data) {
    this->initDeferredRender();
    this->initView();
    this->initKeybinds();
    this->initFonts();
    this->initTextures();
    this->initPausedMenu();
    this->initShaders();

    this->initHeroes();
    this->initHeroGUI();
    this->initTileMap();
}

GameState::~GameState() {
    delete this->pmenu;
    delete this->hero;
    delete this->heroGUI;
    delete this->tileMap;
}

void GameState::initView() {
    this->view.setSize(
            sf::Vector2f(
                    static_cast<float>(this->stateData->gfxSettings->resolution.width),
                    static_cast<float>(this->stateData->gfxSettings->resolution.height)
            )
    );

    this->view.setCenter(
            sf::Vector2f(
                    static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
                    static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
            )
    );
}

void GameState::initKeybinds() {
    std::ifstream ifs("../Config/gamestate_keybinds.ini");

    if (ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
            this->keybinds[key] = this->supportedKeys->at(key2);
    }
    ifs.close();
}

void GameState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf"))
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

void GameState::initTextures() {
    if (!this->textures["HERO_SHEET"].loadFromFile("../Resources/Images/Images/Sprites/Hero/Woodcutter_animations.png"))
        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HERO_TEXTURE";
}


void GameState::initPausedMenu() {
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
    this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

    this->pmenu->addButton("QUIT", gui::p2pY(62.5f, vm)/*450.f*/, gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm), gui::calcCharSize(vm), "Quit");
}

void GameState::initShaders() {

    if(!this->core_shader.loadFromFile("../vertex_shader.vert", "../fragment_shader.frag")){

        std::cout<<"ERROR::GAMESTATE::COULD NOT LOAD SHADER." << "\n";
    }
}

void GameState::initHeroes() {
    this->hero = new Hero(20, 20, this->textures["HERO_SHEET"]);
}

void GameState::initHeroGUI() {
    this->heroGUI = new HeroGUI(this->hero, this->stateData->gfxSettings->resolution);
}

void GameState::initTileMap() {
//TODO cambiare dimensioni mappa
    this->tileMap = new TileMap(this->stateData->gridSize, 100, 100, "../Resources/Images/Tiles/TileSet.png");
    this->tileMap->loadFromFile("../saves_file.txt");
}

void GameState::initDeferredRender() {
    this->renderTexture.create(this->stateData->gfxSettings->resolution.width, this->stateData->gfxSettings->resolution.height);
    this->renderSprite.setTexture(this->renderTexture.getTexture());
    this->renderSprite.setTextureRect(sf::IntRect(0, 0, this->stateData->gfxSettings->resolution.width, this->stateData->gfxSettings->resolution.height));
}

void GameState::updateView(const float &dt) {
    this->view.setCenter(
            std::floor(this->hero->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
            std::floor(this->hero->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
            );

    if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f){
        this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
    }
    else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeF().x){
        this->view.setCenter(this->tileMap->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
    }
    if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f){
        this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
    }
    else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeF().y){
        this->view.setCenter(this->view.getSize().x / 2.f, this->tileMap->getMaxSizeF().y - this->view.getCenter().y);
    }

    this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize * 2);
    this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);


}

void GameState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime()){
        if(!this->paused)
            this->pauseState();
        else
            this->unpauseState();
    }
}

void GameState::updateHeroInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->hero->move(-1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->hero->move(1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))){
        this->hero->move(0.f, -1.f, dt);
        if(this->getKeyTime())
        this->hero->gainEXP(10);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))){
        this->hero->move(0.f, 1.f, dt);
        if(this->getKeyTime())
            this->hero->loseEXP(10);
    }
}

void GameState::updateHeroGUI(const float &dt) {
    this->heroGUI->update(dt);
}

void GameState::updatePauseMenuButtons() {
    if(this->pmenu->isButtonPressed("QUIT"))
        this->endState();
}

void GameState::updateTileMap(const float &dt) {
    this->tileMap->update();
    this->tileMap->updateCollision(this->hero, dt);
}

void GameState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateInput(dt);
    this->updateKeyTime(dt);

    if(!this->paused) {
        this->updateView(dt);
        this->updateHeroInput(dt);
        this->updateTileMap(dt);
        this->hero->update(dt, this->mousePosView);
        this->heroGUI->update(dt);
    }
    else{
        this->pmenu->update(this->mousePosWindow);
        this->updatePauseMenuButtons();
    }
}

void GameState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    this->renderTexture.clear();

    this->renderTexture.setView(this->view);

    this->tileMap->render(
            this->renderTexture,
     this->viewGridPosition,
       &this->core_shader,
    this->hero->getCenter(),
   false
   );

    this->hero->render(this->renderTexture, &this->core_shader, false);

    this->tileMap->renderDeferred(this->renderTexture, &this->core_shader, this->hero->getCenter());

    this->renderTexture.setView(this->renderTexture.getDefaultView());
    this->heroGUI->render(this->renderTexture);

    if(this->paused){
        //this->renderTexture.setView(this->renderTexture.getDefaultView());
        this->pmenu->render(this->renderTexture);
    }

    this->renderTexture.display();
    this->renderSprite.setTexture(this->renderTexture.getTexture());
    target->draw(this->renderSprite);
}


