//
// Created by alpacox on 27/09/21.
//


#include <unistd.h>
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
        : State(window, supportedKeys, states)
{
    this->iniFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }

}

void MainMenuState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->renderButtons(target);
}

void MainMenuState::endState() {
    std::cout << "MainMenuState: io ho finito qui!" << "\n";
}

void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();

}

void MainMenuState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateButtons();
}

void MainMenuState::iniFonts() {

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
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }

}

void MainMenuState::initKeybinds() {

    std::ifstream ifs("../Config/mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons() {

    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
         &this->font, "New Game",
 sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
         &this->font, "Quit",
         sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void MainMenuState::updateButtons() {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }

    if (this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}
