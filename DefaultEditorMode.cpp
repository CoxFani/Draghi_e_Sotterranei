//
// Created by alpacox on 29/11/21.
//

#include "DefaultEditorMode.h"

DefaultEditorMode::DefaultEditorMode(StateData *state_data, TileMap* tile_map, sf::Font* font)
: EditorMode(state_data, tile_map, font) {
    this->initVariables();
    this->initGui();
}

DefaultEditorMode::~DefaultEditorMode() {
    delete this->textureSelector;
}

void DefaultEditorMode::initVariables() {
    this->textureRect = sf::IntRect(0, 0, static_cast<int>(this->stateData->gridSize), static_cast<int>(this->stateData->gridSize));
    this->collision = false;
    this->type = TileTypes::DEFAULT;
    this->layer = 0;
    this->tileAddLock = false;
}

void DefaultEditorMode::initGui() {

    //Testo
    this->cursorText.setFont(*this->font);
    this->cursorText.setFillColor(sf::Color::White);
    this->cursorText.setCharacterSize(20);
    this->cursorText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);

    //Gui generale
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
    this->textureSelector = new gui::TextureSelector(60.f, 20.f, 448.f, 416.f,
                                                     this->stateData->gridSize, this->tileMap->getTileSheet(),
                                                     *this->font, "TS");
}

void DefaultEditorMode::updateInput(const float &dt) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime()){
        if(!this->sidebar.getGlobalBounds().contains(sf::Vector2f(this->mousePosWindow))) {
            if (!this->textureSelector->getActive() ) {
                if(this->tileAddLock){
                    if(this->tileMap->tileEmpty(this->mousePosGrid.x, this->mousePosGrid.y, 0))
                        this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect, this->collision, this->type);
                }
                else
                    this->tileMap->addTile(this->mousePosGrid.x, this->mousePosGrid.y, 0, this->textureRect, this->collision, this->type);
            } else
                this->textureRect = this->textureSelector->getTextureRect();
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_TILE_LOCK"))) && this->getKeyTime()){
        if(this->tileAddLock)
            this->tileAddLock = false;
        else
            this->tileAddLock = true;
    }
}

void DefaultEditorMode::updateGui(const float &dt) {
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
       "\n" << "Type: " << this->type <<
       "\n" << "Tiles: " << this->tileMap->getLayerSize(this->mousePosGrid.x, this->mousePosGrid.y, this->layer) <<
       "\n" << "Tile lock: " << this->tileAddLock;
    this->cursorText.setString(ss.str());
}

void DefaultEditorMode::update(const float &dt) {

}

void DefaultEditorMode::renderGui(sf::RenderTarget &target) {
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

void DefaultEditorMode::render(sf::RenderTarget *target) {

}




