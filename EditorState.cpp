//
// Created by alpacox on 05/10/21.
//

#include "precompiler.h"
#include "EditorState.h"

EditorState::EditorState(StateData* state_data)
        : State(state_data)
{
    this->initVariables();
    this->initView();
    this->initBackground();
    this->initFonts();
    this->initText();
    this->initKeybinds();
    this->initPausedMenu();
    this->initButtons();
    this->initTileMap();
    this->initGui();

}

EditorState::~EditorState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }

    delete this->pmenu;

    delete this->tileMap;

    delete this->textureSelector;
}

void EditorState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->setView(this->view);
    this->tileMap->render(*target);

    target->setView(this->window->getDefaultView());
    this->renderButtons(*target);

    this->renderGui(*target);

    if(this->paused){
        target->setView(this->window->getDefaultView());
        this->pmenu->render(*target);
    }
}

void EditorState::updateInput(const float &dt) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime()){
        if(!this->paused)
            this->pauseState();
        else
            this->unpauseState();
    }
}

void EditorState::update(const float& dt) {
    this->updateMousePosition(&this->view);
    this->updateKeyTime(dt);
    this->updateInput(dt);

    if(!this->paused){
        this->updateButtons();
        this->updateGui(dt);
        this->updateEditorInput(dt);
    }
    else{
        this->pmenu->update(this->mousePosWindow);
        this->updatePauseMenuButtons();
    }
}

void EditorState::initFonts() {

    /*
      char *stringa = get_current_dir_name();
    if(stringa != nullptr){
        std::cout<<"stringa piena" << "\n";
        for(int i=0; i<100; i++){                 //Capiamo dove siamo
    std::cout << stringa[i] ;} std::cout << endl;  } //Attuale percorso file
    else
        std::cout<<"stringa vuota" << endl ;
        */
    if(!this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf")){
        throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
    }

}

void EditorState::initKeybinds() {

    std::ifstream ifs("../Config/editorstate_keybinds.ini");

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

    /* this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S"); */
}

void EditorState::initButtons() {

}

void EditorState::updateButtons() {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosWindow);
    }
}

void EditorState::renderButtons(sf::RenderTarget& target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void EditorState::initBackground() {

}

void EditorState::initVariables() {

    this->textureRect = sf::IntRect(0, 0, static_cast<int>(this->stateData->gridSize), static_cast<int>(this->stateData->gridSize));
    this->collision = false;
    this->type = TileTypes::DEFAULT;
    this->cameraSpeed = 300.f;
}

void EditorState::initPausedMenu() {
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 450.f, "Quit");
    this->pmenu->addButton("SAVE", 350.f, "Save");
    this->pmenu->addButton("LOAD", 300.f, "Load");
}

void EditorState::updatePauseMenuButtons() {
    if( this->pmenu->isButtonPressed("QUIT"))
        this->endState();

    if( this->pmenu->isButtonPressed("SAVE"))
        this->tileMap->saveToFile("../save_files.txt");

    if( this->pmenu->isButtonPressed("LOAD"))
        this->tileMap->loadFromFile("../save_files.txt");
}


void EditorState::initTileMap() {

    this->tileMap = new TileMap(this->stateData->gridSize, 10, 10,"../Resources/Images/Tiles/tilesheet1.png"); //TODO cambiare file per texture selector
}

void EditorState::initGui() {

    this->sidebar.setSize(sf::Vector2f(80.f, static_cast<float>(this->stateData->gfxSettings->resolution.height)));
    this->sidebar.setFillColor(sf::Color(50, 50, 50, 100));
    this->sidebar.setOutlineThickness(1.f);
    this->sidebar.setOutlineColor(sf::Color(200, 200, 200, 150));

    this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize, this->stateData->gridSize));

    this->selectorRect.setFillColor(sf::Color(255, 255, 255, 150));
    this->selectorRect.setOutlineThickness(1.f);
    this->selectorRect.setOutlineColor(sf::Color::Green);

    this->selectorRect.setTexture(this->tileMap->getTileSheet());
    this->selectorRect.setTextureRect(this->textureRect);

    //TODO cambiare dimensioni texture selector
    this->textureSelector = new gui::TextureSelector(20.f, 20.f, 800.f, 200.f,
                                                     this->stateData->gridSize, this->tileMap->getTileSheet(),
                                                     this->font, "TS");


}

void EditorState::updateGui(const float& dt) {

    this->textureSelector->update(this->mousePosWindow, dt);

    if(!this->textureSelector->getActive()) {
        this->selectorRect.setTextureRect(this->textureRect);
        this->selectorRect.setPosition(this->mousePosGrid.x * this->stateData->gridSize,
                                       this->mousePosGrid.y * this->stateData->gridSize);
    }

    this->cursorText.setPosition(this->mousePosView.x + 100.f, this->mousePosView.y - 25.f);
    std::stringstream  ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y <<
    "\n" << this->mousePosGrid.x << " " << this->mousePosGrid.y <<
    "\n" << this->textureRect.left << " " << this->textureRect.top <<
    "\n" << "Collision: " << this->collision <<
    "\n" << "Type: " << this->type;
    this->cursorText.setString(ss.str());
}

void EditorState::renderGui(sf::RenderTarget &target) {

    if(!this->textureSelector->getActive()) {
        target.setView(this->view);
        target.draw(this->selectorRect);
    }

    target.setView(this->window->getDefaultView());
    this->textureSelector->render(target);
    target.draw(this->sidebar);

    target.setView(this->view);
    target.draw(this->cursorText);

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


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime()){
        if(!this->sidebar.getGlobalBounds().contains(sf::Vector2f(this->mousePosWindow))) {
            if (!this->textureSelector->getActive() ) {
                this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect, this->collision, this->type);
            } else {
                this->textureRect = this->textureSelector->getTextureRect();
            }
        }
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->getKeyTime()){
        if(!this->sidebar.getGlobalBounds().contains(sf::Vector2f(this->mousePosWindow))) {
            if (!this->textureSelector->getActive())
                this->tileMap->removeTile(this->mousePosGrid.x, this->mousePosGrid.y, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_COLLISION"))) && this->getKeyTime()){
        if (this->collision)
            this->collision = false;
        else
            this->collision = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INCREASE_TYPE"))) && this->getKeyTime()){
        ++this->type;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("DECREASE_TYPE"))) && this->getKeyTime()){
        if(this->type > 0)
            --this->type;
    }
}

void EditorState::initText() {

    this->cursorText.setFont(this->font);
    this->cursorText.setFillColor(sf::Color::White);
    this->cursorText.setCharacterSize(20);
    this->cursorText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
}

void EditorState::initView() {
    this->view.setSize(sf::Vector2f(static_cast<float>(this->stateData->gfxSettings->resolution.width), static_cast<float>(this->stateData->gfxSettings->resolution.height)));
    this->view.setCenter(static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f, static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f);
}
