//
// Created by gabriele on 13/12/21.
//

#include "precompiler.h"
#include "AIFollow.h"

AIFollow::AIFollow(GameCharacter &self, GameCharacter &gameCharacter)
        : AIOption(self, gameCharacter) {

}

AIFollow::~AIFollow() {

}

void AIFollow::update(const float& dt) {
    sf::Vector2f moveVec;
    moveVec.x = self.getPosition().x - gameCharacter.getPosition().x;
    moveVec.y = self.getPosition().y - gameCharacter.getPosition().y;
    float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
    moveVec /= vecLength;

    if(self.getPosition().x != gameCharacter.getPosition().x)
        self.move(moveVec.x, moveVec.y, dt);
}
