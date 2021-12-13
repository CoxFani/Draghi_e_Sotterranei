//
// Created by alpacox on 13/12/21.
//

#include "precompiler.h"
#include "AIComponent.h"

AIComponent::AIComponent(GameCharacter& self, GameCharacter& gameCharacter)
: self(self), gameCharacter(gameCharacter){

}

AIComponent::~AIComponent() {

}

void AIComponent::update(const float &dt) {

}
