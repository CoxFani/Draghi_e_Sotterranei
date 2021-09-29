//
// Created by alpacox on 26/03/21.
//

#include "GameState.h"
#include <map>

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState() {

}

void GameState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    this->player.render(target);
    }

void GameState::endState() {
    std::cout << "GameState: io ho finito qui!" << "/n";
}

void GameState::updateInput(const float &dt) {
    this->checkForQuit();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);
    this->player.update(dt);
}

void GameState::initKeybinds() {

    std::ifstream ifs("../Config/gamestate_keybinds.ini");

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
/*
    this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    */
}

/* POINTZERO
GameState::GameState(Hero* hero1) {

    this -> hero = hero1;

}

GameState::~GameState() noexcept {

}

void GameState::printMenu() const {
    system("read -p 'Press Enter to continue...' var"); //Aspetta un mio comando per continuare
    //
    //system("clear"); //Ripulisce la schermata
    cout<< "---- MAIN MENU ----" << "\n" << "\n"
        << " (0) Quit" << "\n"
        << " (1) Character Stats" << "\n"
        << " (2) Inventory" << "\n"
        << " (3) Options" << "\n"
        << " (4) Level Up" << "\n";

}

const int GameState::getChoice() const {
    int choice = 0;

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

void GameState::updateMenu() {

    switch (this -> getChoice() ){
        case 0:
            cout << setw(7) << "---- QUITTING GAME ----" << "\n";  //setw(7) lascia 7 spazi da inizio riga
            this->setQuit(true);
            break;

        case 1:
            cout << setw(7) << "---- Character Stats ----" << "\n" << "\n";
            std::cout << this -> hero -> toString() << "\n";
            break;

        case 2:
            cout << setw(7) << "---- Inventory ----" << "\n";
            //TODO stampa inventario
            break;

        case 3:
            cout << setw(7) << "---- Options ----" << "\n";
            //TODO opzioni audio e video
            break;

        case 4:
            cout << setw(7) << "---- LEVEL UP! -----" << "\n" ;
            this -> hero -> levelUpStats();
            break;


        default:
            cout << setw(7) << "---- ERROR 404: OPTION NOT FOUD, try again! ----" << "\n";
            break;

    }
}

void GameState::update() {

    this -> printMenu();

    this -> updateMenu();

}
 */
