//
// Created by alpacox on 26/03/21.
//

#include "GameState.h"
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