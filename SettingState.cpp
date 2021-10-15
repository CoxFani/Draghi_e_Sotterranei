//
// Created by alpacox on 08/10/21.
//

#include "SettingState.h"


SettingState::SettingState(sf::RenderWindow* window, GraphicsSettings& gfxSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
: State(window, supportedKeys, states), gfxSettings(gfxSettings){

    this->initVariables();
    this->initBackground();
    this->iniFonts();
    this->initKeybinds();
    this->initGui();
    this->initText();
}

SettingState::~SettingState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }

    auto count = this->dropdownList.begin();
    for (count = this->dropdownList.begin(); count != this->dropdownList.end(); ++count)
    {
        delete count->second;
    }
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

void SettingState::initGui() {


    this->buttons["BACK"] = new gui::Button(
            1100.f, 600.f, 200.f, 75.f,
            &this->font, "Back", 50,
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["APPLY"] = new gui::Button(
            900.f, 600.f, 200.f, 75.f,
            &this->font, "Apply", 50,
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    std::vector<std::string> modes_str;
    for (auto &i : this->modes){
        modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
    }

    this->dropdownList["RESOLUTION"] = new gui::DropDownList(400, 300, 200, 50, font, modes_str.data(), modes_str.size());
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
    this->modes = sf::VideoMode::getFullscreenModes();
}

void SettingState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateGui(dt);
}

void SettingState::updateInput(const float &dt) {

}

void SettingState::updateGui(const float &dt) {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }


    if (this->buttons["BACK"]->isPressed()){
        this->endState();
    }

    if (this->buttons["APPLY"]->isPressed()){
        //TEST da rimuovere
        this->gfxSettings.resolution = this->modes[this->dropdownList["RESOLUTION"]->getActiveElementId()];

        this->window->create(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Default);
    }

    for (auto &i : this->dropdownList)
    {
        i.second->update(this->mousePosView, dt);
    }
}

void SettingState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->renderGui(*target);

    target->draw(this->optionsText);

    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(20);
    std::stringstream  ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target-> draw(mouseText);
}

void SettingState::renderGui(sf::RenderTarget& target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }

    for (auto &i : this->dropdownList)
    {
        i.second->render(target);
    }
}

void SettingState::initText() {
    this->optionsText.setFont(this->font);
    this->optionsText.setPosition(sf::Vector2f(100.f, 300.f));
    this->optionsText.setCharacterSize(30);
    this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
    this->optionsText.setString("Resolution \n\n\nFullscreen \n\n\nVsync \n\n\nAntialising \n\n\n ");
}


