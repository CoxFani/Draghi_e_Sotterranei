//
// Created by alpacox on 29/11/21.
//

#include "precompiler.h"
#include "EditorMode.h"

EditorMode::EditorMode(StateData *state_data, TileMap* tile_map, EditorStateData* editor_state_data)
:stateData(state_data), tileMap(tile_map), editorStateData(editor_state_data){

}

EditorMode::~EditorMode() {

}

const bool EditorMode::getKeyTime() {
    if(*this->editorStateData->keyTime >= *this->editorStateData->keyTimeMax){
        *this->editorStateData->keyTime = 0.f;
        return true;
    }
    return false;
}
