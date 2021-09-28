//
// Created by alpacox on 27/09/21.
//


#include <unistd.h>
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
        : State(window, supportedKeys)
{
    this->iniFonts();
    this->initKeybinds();

    this->gamestate_btn = new Button(100, 100, 150, 50,
                                     &this->font, "New Game",
                                     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {
    delete this->gamestate_btn;

}

void MainMenuState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->gamestate_btn->render(target);
}

void MainMenuState::endState() {
    std::cout << "GameState: io ho finito qui!" << "/n";
}

void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();

}

void MainMenuState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);

    this->gamestate_btn->update(this->mousePosView);
}

void MainMenuState::iniFonts() {

    /*char *stringa = get_current_dir_name();
    if(stringa != nullptr){
        std::cout<<"stringa piena" << "\n";
        for(int i=0; i<100; i++){                 //Capiamo dove siamo
    std::cout << stringa[i] ;} std::cout << endl;  } //Attuale percorso file
    else
        std::cout<<"stringa vuota" << endl ; */
    if(!this->font.loadFromFile("../Fonts/yoster.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }

}

void MainMenuState::initKeybinds() {

    /* TODO sostituire comandi con file
    std::ifstream ifs("Config/gamestate_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close(); */

    this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}