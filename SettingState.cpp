//
// Created by alpacox on 08/10/21.
//

#include "precompiler.h"
#include "SettingState.h"


SettingState::SettingState(StateData* state_data)
: State(state_data){
    this->initVariables();
    this->iniFonts();
    this->initKeybinds();
    this->initGui();
}

SettingState::~SettingState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i){
        delete i->second;
    }

    auto count = this->dropdownList.begin();
    for (count = this->dropdownList.begin(); count != this->dropdownList.end(); ++count){
        delete count->second;
    }
}

void SettingState::iniFonts() {
    if(!this->font.loadFromFile("../Fonts/DeterminationMonoWebRegular-Z5oq.ttf")){
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void SettingState::initKeybinds() {
    std::ifstream ifs("../Config/mainmenustate_keybinds.ini");

    if (ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2){
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
}

void SettingState::initGui() {
    const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

    //Background
    this->background.setSize(
            sf::Vector2f(
                    static_cast<float>(vm.width),
                    static_cast<float>(vm.height)
            )
    );

    if(this->backgroundTexture.loadFromFile("../Resources/Images/Backgrounds/Menu002.png")){
        //throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE"; <--- DA ERRORE
    }

    this->background.setTexture(&this->backgroundTexture);

    //Buttons
    this->buttons["BACK"] = new gui::Button(
            gui::p2pX(85.9f, vm), gui::p2pY(83.3f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "Back", gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["APPLY"] = new gui::Button(
            gui::p2pX(70.3f, vm), gui::p2pY(83.3f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "Apply", gui::calcCharSize(vm),
            sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    //Modes
    std::vector<std::string> modes_str;
    for (auto &i : this->modes)
        modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));

    //DropDownList
    this->dropdownList["RESOLUTION"] = new gui::DropDownList(gui::p2pX(31.2f, vm), gui::p2pY(41.6f, vm),
                                                             gui::p2pX(15.6f, vm), gui::p2pY(6.9f, vm),
                                                             font, modes_str.data(), modes_str.size());

    //Text
    this->optionsText.setFont(this->font);
    this->optionsText.setPosition(sf::Vector2f(gui::p2pX(7.81f, vm), gui::p2pY(41.6f, vm)));
    this->optionsText.setCharacterSize(gui::calcCharSize(vm, 60));
    this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
    this->optionsText.setString("Resolution \n\n\nFullscreen \n\n\nVsync \n\n\nAntialising \n\n\n ");
}



void SettingState::resetGui() {
/*
     * cancella gli elementi della GUI e li re-inizializza
     *
     * @return void
     */

    auto i = this->buttons.begin();
    for(i = this->buttons.begin(); i != this->buttons.end(); ++i){
        delete i->second;
    }
    this->buttons.clear();

    auto j = this->dropdownList.begin();
    for(j = this->dropdownList.begin(); j != dropdownList.end(); ++j){
        delete j->second;
    }
    this->dropdownList.clear();

    this->initGui();
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
        i.second->update(this->mousePosWindow);

    if (this->buttons["BACK"]->isPressed())
        this->endState();

    if (this->buttons["APPLY"]->isPressed()){
        //TEST da rimuovere
        this->stateData->gfxSettings->resolution = this->modes[this->dropdownList["RESOLUTION"]->getActiveElementId()];

        this->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, sf::Style::Default);

        this->resetGui();
    }

    for (auto &i : this->dropdownList)
        i.second->update(this->mousePosWindow, dt);
}

void SettingState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(this->background);

    this->renderGui(*target);

    target->draw(this->optionsText);

    //TODO commentare le seguenti linee per togliere le coordinate del mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(20);
    std::stringstream  ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target-> draw(mouseText);
    //***************************************************************************************
}

void SettingState::renderGui(sf::RenderTarget& target) {

    for (auto &i : this->buttons)
        i.second->render(target);

    for (auto &i : this->dropdownList)
        i.second->render(target);
}








