//
// Created by gabriele on 21/12/21.
//

#include "precompiler.h"
#include "GameManager.h"

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::subscribe(Observer *obs) {

    observers.push_back(obs);
}

void GameManager::unsubscribe(Observer *obs) {

    observers.remove(obs);
}

void GameManager::notify() {

    for(auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update();
}
