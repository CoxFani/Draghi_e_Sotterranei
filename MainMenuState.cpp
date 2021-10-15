//
// Created by alpacox on 27/09/21.
//


#include <unistd.h>
#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, GraphicsSettings& gfxSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
        : State(window, supportedKeys, states), gfxSettings(gfxSettings)
{
    this->initVariables();
    this->initBackground();
    this->iniFonts();
    this->initKeybinds();
    this->initButtons();

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

    this->renderButtons(*target);

    //DA COMMENTARE SUCCESSIVAMENTE: Aiuta a trovare le coordinate sullo schermo per posizionare cose
    /*
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(20);
    std::stringstream  ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target-> draw(mouseText);
     */
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
}


void MainMenuState::updateInput(const float &dt) {

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

    this->buttons["GAME_STATE"] = new gui::Button(
            100.f, 300.f, 200.f, 75.f,
         &this->font, "New Game", 50,
 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
 sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["SETTINGS_STATE"] = new gui::Button(
            100.f, 400.f, 200.f, 75.f,
         &this->font, "Settings", 50,
 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
 sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["EDITOR_STATE"] = new gui::Button(
            100.f, 500.f, 200.f, 75.f,
         &this->font, "Editor", 50,
 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
 sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["EXIT_STATE"] = new gui::Button(
            100.f, 600.f, 200.f, 75.f,
         &this->font, "Quit", 50,
sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::updateButtons() {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }

    if (this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    if (this->buttons["SETTINGS_STATE"]->isPressed()){
        this->states->push(new SettingState(this->window, this->gfxSettings, this->supportedKeys, this->states));
    }

    if (this->buttons["EDITOR_STATE"]->isPressed()){
        this->states->push(new EditorState(this->window, this->supportedKeys, this->states));
    }

    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void MainMenuState::initBackground() {

    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>(this->window->getSize().x),
                    static_cast<float>(this->window->getSize().y)
            )
    );

    if(this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/Menu002.png")){
        //throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE"; <--- DA ERRORE
    }

    this->background.setTexture(&this->backgroundTexture);

}

void MainMenuState::initVariables() {

}
