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
    moveVec.x = gameCharacter.getPosition().x - self.getPosition().x;
    moveVec.y = gameCharacter.getPosition().y - self.getPosition().y;
    float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
    moveVec /= vecLength;

    if((self.getPosition().x != gameCharacter.getPosition().x) && std::abs(vecLength) < 200.f) // Aggro -> 200
        self.move(moveVec.x, moveVec.y, dt);
}