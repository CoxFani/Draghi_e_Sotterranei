//
// Created by alpacox on 05/10/21.
//

#include "EditorState.h"

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
        : State(window, supportedKeys, states)
{
    this->initVariables();
    this->initBacground();
    this->iniFonts();
    this->initKeybinds();
    this->initButtons();

}

EditorState::~EditorState() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }

}

void EditorState::render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    this->renderButtons(target);

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


void EditorState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key(this->keybinds.at("CLOSE")))))
        this->endState();

}

void EditorState::update(const float& dt) {
    this->updateMousePosition();
    this->updateInput(dt);

    this->updateButtons();
}

void EditorState::iniFonts() {

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
        throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
    }

}

void EditorState::initKeybinds() {

    std::ifstream ifs("../Config/editorstate_keybinds.ini");

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

void EditorState::initButtons() {

}

void EditorState::updateButtons() {

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }
}

void EditorState::renderButtons(sf::RenderTarget *target) {

    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void EditorState::initBacground() {

}

void EditorState::initVariables() {

}
