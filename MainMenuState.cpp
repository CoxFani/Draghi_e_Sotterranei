//
// Created by alpacox on 27/09/21.
//

#include "precompiler.h"
#include "MainMenuState.h"

MainMenuState::MainMenuState(StateData* state_data)
        : State(state_data)
{
    this->initVariables();
    this->iniFonts();
    this->initKeybinds();
    this->initGui();
    this->resetGui();

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

    //DA COMMENTARE SUCCESSIVAMENTE (fatto): Aiuta a trovare le coordinate sullo schermo per posizionare cose
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

    this->updateGui();
}

void MainMenuState::iniFonts() {
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
}

void MainMenuState::initGui() {

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

    this->buttons["GAME_STATE"] = new gui::Button(
            gui::p2pX(7.81f, vm), gui::p2pY(41.6f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "New Game", gui::calcCharSize(vm),
            sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
            sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["SETTINGS_STATE"] = new gui::Button(
            gui::p2pX(7.81f, vm), gui::p2pY(55.5f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "Settings", gui::calcCharSize(vm),
            sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
            sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["EDITOR_STATE"] = new gui::Button(
            gui::p2pX(7.81f, vm), gui::p2pY(69.4f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "Editor", gui::calcCharSize(vm),
            sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
            sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["EXIT_STATE"] = new gui::Button(
            gui::p2pX(7.81f, vm), gui::p2pY(83.3f, vm),
            gui::p2pX(15.6f, vm), gui::p2pY(10.4f, vm),
            &this->font, "Quit", gui::calcCharSize(vm),
            sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
            sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::resetGui() {
    /*
     * cancella gli elementi della GUI e li re-inizializza
     *
     * @return void
     */

    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }
    this->buttons.clear();

    this->initGui();

}

void MainMenuState::updateGui() {
    for (auto &i : this->buttons){
        i.second->update(this->mousePosWindow);
    }

    if (this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->stateData));
    }

    if (this->buttons["SETTINGS_STATE"]->isPressed()){
        this->states->push(new SettingState(this->stateData));
    }

    if (this->buttons["EDITOR_STATE"]->isPressed()){
        this->states->push(new EditorState(this->stateData));
    }

    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for (auto &i : this->buttons){
        i.second->render(target);
    }
}



void MainMenuState::initVariables() {

}


