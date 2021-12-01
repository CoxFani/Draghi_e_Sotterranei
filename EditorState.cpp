//
// Created by alpacox on 05/10/21.
//

#include "precompiler.h"
#include "EditorState.h"

EditorState::EditorState(StateData* state_data)
        : State(state_data)
{
    this->initVariables();
    this->initEditorStateData();
    this->initView();
    this->initFonts();
    this->initKeybinds();
    this->initPausedMenu();
    this->initButtons();
    this->initTileMap();
    this->initGui();

    this->initModes();

}

EditorState::~EditorState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
        delete i->second;
    delete this->pmenu;
    delete this->tileMap;

    for(size_t i = 0; i < this->modes.size(); i++){
        delete this->modes[i];
    }
}

void EditorState::initVariables() {

    this->cameraSpeed = 1000.f;

}

void EditorState::initEditorStateData() {
    this->editorStateData.view = &this->view;
    this->editorStateData.font = &this->font;
    this->editorStateData.keyTime = &this->keyTime;
    this->editorStateData.keyTimeMax = &this->keyTimeMax;
    this->editorStateData.keybinds = &this->keybinds;
    this->editorStateData.mousePosGrid = &this->mousePosGrid;
    this->editorStateData.mousePosScreen = &this->mousePosScreen;
    this->editorStateData.mousePosView = &this->mousePosView;
    this->editorStateData.mousePosWindow = &this->mousePosWindow;
}

void EditorState::initFonts() {
    if(!this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf")){
        throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
    }

}

void EditorState::initButtons() {

}

void EditorState::initKeybinds() {
    std::ifstream ifs("../Config/editorstate_keybinds.ini");

    if (ifs.is_open()){
        std::string key = "";
        std::string key2 = "";
        while (ifs >> key >> key2){
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

void EditorState::initPausedMenu() {
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
    this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

    this->pmenu->addButton("QUIT", gui::p2pY(62.5f, vm)/*450.f*/, gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm), gui::calcCharSize(vm), "Quit");
    this->pmenu->addButton("SAVE", gui::p2pY(48.6f, vm)/*350.f*/, gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm), gui::calcCharSize(vm), "Save");
    this->pmenu->addButton("LOAD", gui::p2pY(34.7f, vm)/*250.f*/, gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm), gui::calcCharSize(vm), "Load");
}

void EditorState::initGui() {


}

void EditorState::initTileMap() {
    this->tileMap = new TileMap(this->stateData->gridSize, 100, 100,"../Resources/Images/Tiles/TileSet.png"); //TODO cambiare file per texture selector
}

void EditorState::initView() {
    this->view.setSize(sf::Vector2f(static_cast<float>(this->stateData->gfxSettings->resolution.width), static_cast<float>(this->stateData->gfxSettings->resolution.height)));
    this->view.setCenter(static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f, static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f);
}

void EditorState::initModes() {
    this->modes.push_back(new DefaultEditorMode(this->stateData, this->tileMap, &this->editorStateData));
    this->modes.push_back(new EnemyEditorMode(this->stateData, this->tileMap, &this->editorStateData));
    this->activeMode = EditorModes::DEFAULT_EDITOR_MODE;
}

void EditorState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime()){
        if(!this->paused)
            this->pauseState();
        else
            this->unpauseState();
    }
}

void EditorState::updateEditorInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_UP")))){
        this->view.move(0.f, -std::floor(this->cameraSpeed * dt)); //valore regola velocità scorrimento schermo
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_DOWN")))){
        this->view.move(0.f, std::floor(this->cameraSpeed * dt)); //valore regola velocità scorrimento schermo
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_LEFT")))){
        this->view.move(-std::floor(this->cameraSpeed * dt), 0.f); //valore regola velocità scorrimento schermo
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_RIGHT")))){
        this->view.move(std::floor(this->cameraSpeed * dt), 0.f); //valore regola velocità scorrimento schermo
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))){
        if(this->activeMode < this->modes.size() - 1){
            this->activeMode++;
        }
        else {
            std::cout << "ERROR::EDITORSTATE::CANNOT CHANGE MODE  UP!" << "\n";
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))){
        if(this->activeMode > 0){
            this->activeMode--;
        }
        else {
            std::cout << "ERROR::EDITORSTATE::CANNOT CHANGE MODE DOWN!" << "\n";
        }
    }
}

void EditorState::updateButtons() {
    for (auto &i : this->buttons){
        i.second->update(this->mousePosWindow);
    }
}

void EditorState::updateGui(const float& dt) {

}

void EditorState::updatePauseMenuButtons() {
    if( this->pmenu->isButtonPressed("QUIT"))
        this->endState();

    if( this->pmenu->isButtonPressed("SAVE"))
        this->tileMap->saveToFile("../saves_file.txt");

    if( this->pmenu->isButtonPressed("LOAD"))
        this->tileMap->loadFromFile("../saves_file.txt");
}

void EditorState::updateModes(const float& dt) {

    this->modes[this->activeMode]->update(dt);

}

void EditorState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateKeyTime(dt);
    this->updateInput(dt);

    if(!this->paused){
        this->updateButtons();
        this->updateGui(dt);
        this->updateEditorInput(dt);
        this->updateModes(dt);
    }
    else{
        this->pmenu->update(this->mousePosWindow);
        this->updatePauseMenuButtons();
    }
}

void EditorState::renderButtons(sf::RenderTarget& target) {
    for (auto &i : this->buttons){
        i.second->render(target);
    }
}

void EditorState::renderGui(sf::RenderTarget &target) {

}

void EditorState::renderModes(sf::RenderTarget& target) {

    this->modes[this->activeMode]->render(target);

}

void EditorState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;


    target->setView(this->view);
    this->tileMap->render(*target, this->mousePosGrid, nullptr, sf::Vector2f(), true);
    this->tileMap->renderDeferred(*target);

    target->setView(this->window->getDefaultView());
    this->renderButtons(*target);

    this->renderGui(*target);

    this->renderModes(*target);

    if(this->paused){
        target->setView(this->window->getDefaultView());
        this->pmenu->render(*target);
    }
}








