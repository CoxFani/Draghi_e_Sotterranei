//
// Created by alpacox on 08/10/21.
//

#include "SettingState.h"


SettingState::SettingState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
: State(window, supportedKeys, states){

    this->initVariables();
    this->initBackground();
    this->iniFonts();
    this->initKeybinds();
    this->initButtons();
}

SettingState::~SettingState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
    delete this->ddl;

}

void SettingState::iniFonts() {

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

void SettingState::initKeybinds() {

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

void SettingState::initButtons() {


    this->buttons["EXIT_STATE"] = new gui::Button(
            100.f, 600.f, 200.f, 75.f,
            &this->font, "Quit", 50,
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    std::string lis[] = {"a", "aaa", "aaaaaa", "aaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaa"};
    this->ddl = new gui::DropDownList(100, 100, 200, 50, font, lis,  5);
}

void SettingState::initBackground() {

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

void SettingState::initVariables() {

}

void SettingState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateButtons();

    this->ddl->update(this->mousePosView, dt);
}

void SettingState::updateInput(const float &dt) {

}

void SettingState::updateButtons() {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }


    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }

}

void SettingState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->renderButtons(*target);

    this->ddl->render(*target);

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

void SettingState::renderButtons(sf::RenderTarget& target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}


