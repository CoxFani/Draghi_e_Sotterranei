//
// Created by alpacox on 30/11/21.
//
#include "precompiler.h"
#include "EnemyEditorMode.h"

EnemyEditorMode::EnemyEditorMode(StateData *state_data, TileMap *tile_map, EditorStateData *editor_state_data)
        : EditorMode(state_data, tile_map, editor_state_data) {
    this->initVariables();
    this->initGui();
}

EnemyEditorMode::~EnemyEditorMode() {

}

void EnemyEditorMode::updateInput(const float &dt) {

}

void EnemyEditorMode::updateGui(const float &dt) {
    this->selectorRect.setPosition(this->editorStateData->mousePosGrid->x * this->stateData->gridSize,
                                   this->editorStateData->mousePosGrid->y * this->stateData->gridSize);
    this->cursorText.setPosition(this->editorStateData->mousePosView->x + 100.f,
                                 this->editorStateData->mousePosView->y - 25.f);
    std::stringstream  ss;
    ss <<
       "\n" << "Collision: " <<
       "\n" << "Type: " <<
       "\n" << "Tiles: " <<
       "\n" << "Tile lock: ";
    this->cursorText.setString(ss.str());
}

void EnemyEditorMode::update(const float &dt) {
    this->updateInput(dt);
    this->updateGui(dt);
}

void EnemyEditorMode::renderGui(sf::RenderTarget &target) {
    target.setView(*this->editorStateData->view);
    target.draw(this->selectorRect);
    target.draw(this->cursorText);
}

void EnemyEditorMode::render(sf::RenderTarget &target) {
    this->renderGui(target);
}

void EnemyEditorMode::initGui() {

    //Testo
    this->cursorText.setFont(*this->editorStateData->font);
    this->cursorText.setFillColor(sf::Color::White);
    this->cursorText.setCharacterSize(20);
    this->cursorText.setPosition(this->editorStateData->mousePosView->x, this->editorStateData->mousePosView->y - 50);

    //GUI generale
    this->sidebar.setSize(sf::Vector2f(80.f, static_cast<float>(this->stateData->gfxSettings->resolution.height)));
    this->sidebar.setFillColor(sf::Color(50, 50, 50, 100));
    this->sidebar.setOutlineThickness(1.f);
    this->sidebar.setOutlineColor(sf::Color(200, 200, 200, 150));

    this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize, this->stateData->gridSize));

    this->selectorRect.setFillColor(sf::Color(255, 255, 255, 150));
    this->selectorRect.setOutlineThickness(1.f);
    this->selectorRect.setOutlineColor(sf::Color::Green);
}

void EnemyEditorMode::initVariables() {

}
