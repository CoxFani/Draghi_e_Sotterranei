//
// Created by alpacox on 25/03/21.
//

#include "precompiler.h"
#include "TileMap.h"

TileMap::TileMap(float gridSize, int  width, int  height, std::string texture_file) {
    this->gridSizeF = gridSize;
    this->gridSizeI = static_cast<int>(this->gridSizeF);
    this->maxSizeWorldGrid.x = width;
    this->maxSizeWorldGrid.y = height;
    this->maxSizeWorldF.x = static_cast<float>(width) * gridSize;
    this->maxSizeWorldF.y = static_cast<float>(height) * gridSize;

    this->layers = 1;   //layers<>layer
    this->textureFile = texture_file;

    this->fromX = 0;
    this->toX = 0;
    this->fromY = 0;
    this->toY = 0;
    this->layer = 0;    //layer<>layers

    this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector<Tile*> >());
    for(int x = 0; x < this->maxSizeWorldGrid.x; x++){

        for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
            this->map[x].resize(this->maxSizeWorldGrid.y, std::vector<Tile*>());

            for (int z = 0; z < this->layers; z++) {
                this->map[x][y].resize(this->layers, nullptr);

            }
        }
    }
    if(!this->tileSheet.loadFromFile(textureFile))
        std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";

    this->collisionBox.setSize(sf::Vector2f(gridSize, gridSize));
    this->collisionBox.setFillColor(sf::Color(255, 0, 0, 50));
    this->collisionBox.setOutlineColor(sf::Color::Red);
    this->collisionBox.setOutlineThickness(1.f);
}

TileMap::~TileMap() {
    this->clear();
}

void TileMap::update() {

}

void TileMap::render(sf::RenderTarget &target, GameCharacter* gameCharacter) {
    if(gameCharacter){
        this->layer = 0;

        this->fromX = gameCharacter->getGridPosition(this->gridSizeI).x - 3;
        if(this->fromX < 0)
            this->fromX = 0;
        else if (this->fromX > this->maxSizeWorldGrid.x)
            this->fromX = maxSizeWorldGrid.x;

        this->toX = gameCharacter->getGridPosition(this->gridSizeI).x + 5;
        if(this->toX < 0 )
            this->toX = 0;
        else if (this->toX > this->maxSizeWorldGrid.x)
            this->toX = maxSizeWorldGrid.x;

        this->fromY = gameCharacter->getGridPosition(this->gridSizeI).y - 3;
        if(this->fromY < 0)
            this->fromY = 0;
        else if (this->fromY > this->maxSizeWorldGrid.y)
            this->fromY = maxSizeWorldGrid.y;

        this->toY = gameCharacter->getGridPosition(this->gridSizeI).y + 5;
        if(this->toY < 0)
            this->toY = 0;
        else if (this->toY > this->maxSizeWorldGrid.y)
            this->toY = maxSizeWorldGrid.y;

        for(int x = this->fromX; x < this->toX; x++) {
            for (int y = this->fromY; y < this->toY; y++) {
                this->map[x][y][this->layer]->render(target);
                if (this->map[x][y][this->layer]->getCollision()) {
                    this->collisionBox.setPosition(this->map[x][y][this->layer]->getPosition());
                    target.draw(this->collisionBox);
                }
            }
        }
    }
    else {
        for (auto &x: this->map) {
            for (auto &y: x) {
                for (auto *z: y) {
                    if (z != nullptr) {
                        z->render(target);
                        if (z->getCollision()) {
                            this->collisionBox.setPosition(z->getPosition());
                            target.draw(this->collisionBox);
                        }
                    }
                }
            }
        }
    }
}

void TileMap::addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type) {

    if(x < this->maxSizeWorldGrid.x && x >= 0 &&
       y < this->maxSizeWorldGrid.y && y >= 0 &&
       z < this->layers && z >= 0){

        if(this->map[x][y][z] == nullptr){

            this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->tileSheet,  texture_rect, collision, type);
            std::cout <<"DEBUG: ADDED A TILE!" << "\n";
        }
    }
}

void TileMap::removeTile(const int x, const int y, const int z) {

    if(x < this->maxSizeWorldGrid.x && x >= 0 &&
       y < this->maxSizeWorldGrid.y && y >= 0 &&
       z < this->layers && z >= 0){

        if(this->map[x][y][z] != nullptr){

            delete this->map[x][y][z];
            this->map[x][y][z] = nullptr;
            std::cout <<"DEBUG: REMOVED A TILE!" << "\n";
        }
    }
}

const sf::Texture *TileMap::getTileSheet() const{
    return &this->tileSheet;
}

void TileMap::saveToFile(const std::string file_name) {
    /*Salva tilemap in un file di testo
    * Format:
    * Basic:
    * Size x y
    * gridSize
    * layers
    * texture file
    *
    * All tiles:
    * gridPos x y layer
    * Texture rect x y
    * collision
    * type
    */

    std::ofstream out_file;

    out_file.open(file_name);

    if(out_file.is_open()){

        out_file << this->maxSizeWorldGrid.x << " " << this->maxSizeWorldGrid.y << "\n"
             << this->gridSizeI << "\n"
             << this->layers << "\n"
             << this->textureFile << "\n";

        for(int x = 0; x < this->maxSizeWorldGrid.x; x++){
            for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
                for (int z = 0; z < this->layers; z++) {
                    if(this->map[x][y][z])
                        out_file << x << " " << y << " " << z << " " << this->map[x][y][z]->getAsString() << " ";
                }
            }
        }
    }
    else{
        std::cout << "ERROR::TILEMAP::COULD NOT SAVE TO FILE " << file_name << "\n";
    }

    out_file.close();
    }

void TileMap::loadFromFile(const std::string file_name) {
    std::ifstream in_file;

    in_file.open(file_name);

    if(in_file.is_open()){
        sf::Vector2i size;
        int gridSize = 0;
        int layers = 0;
        std::string texture_file = "";
        int x = 0;
        int y = 0;
        int z = 0;
        int trX = 0;
        int trY = 0;
        bool collision = false;
        short type = 0;
        in_file >> size.x >> size.y >> gridSize >> layers >> texture_file;

        this->gridSizeF = static_cast<float>(gridSize);
        this->gridSizeI = gridSize;
        this->maxSizeWorldGrid.x = size.x;
        this->maxSizeWorldGrid.y = size.y;
        this->layers = layers;
        this->textureFile = texture_file;

        this->clear();

        this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector<Tile*> >());
        for(int x = 0; x < this->maxSizeWorldGrid.x; x++){
            for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
                this->map[x].resize(this->maxSizeWorldGrid.y, std::vector<Tile*>());
                for (int z = 0; z < this->layers; z++) {
                    this->map[x][y].resize(this->layers, nullptr);
                }
            }
        }
        if(!this->tileSheet.loadFromFile(textureFile))
            std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";
        while(in_file >> x >> y >> z >> trX >> trY >> collision >> type){
            this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->tileSheet, sf::IntRect(trX, trY, this->gridSizeI, this->gridSizeI), collision, type);
        }
    }
    else{
        std::cout << "ERROR::TILEMAP::COULD NOT LOAD FROM FILE " << file_name << "\n";
    }

    in_file.close();
}

void TileMap::clear() {
    for(int x = 0; x < this->maxSizeWorldGrid.x; x++){
        for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
            for (int z = 0; z < this->layers; z++) {
                delete this->map[x][y][z];
                this->map[x][y][z] = nullptr;
            }
            this->map[x][y].clear();
        }
        this->map[x].clear();
    }
    this->map.clear();
    //std::cout << this->map.size() << "\n";
}

void TileMap::updateCollision(GameCharacter *gameCharacter, const float& dt) {
    if(gameCharacter->getPosition().x < 0.f) {
        gameCharacter->setPosition(0.f, gameCharacter->getPosition().y);
        gameCharacter->stopVelocityX();
    }
    else if(gameCharacter->getPosition().x + gameCharacter->getGlobalBounds().width > this->maxSizeWorldF.x) {
        gameCharacter->setPosition(this->maxSizeWorldF.x - gameCharacter->getGlobalBounds().width, gameCharacter->getPosition().y);
        gameCharacter->stopVelocityX();
    }
    if(gameCharacter->getPosition().y < 0.f) {
            gameCharacter->setPosition(gameCharacter->getPosition().x, 0.f);
            gameCharacter->stopVelocityY();
    }
    else if(gameCharacter->getPosition().y + gameCharacter->getGlobalBounds().height > this->maxSizeWorldF.y){
            gameCharacter->setPosition(gameCharacter->getPosition().x, this->maxSizeWorldF.y - gameCharacter->getGlobalBounds().height);
            gameCharacter->stopVelocityY();
    }

    this->layer = 0;

    this->fromX = gameCharacter->getGridPosition(this->gridSizeI).x - 1;
    if(this->fromX < 0)
        this->fromX = 0;
    else if (this->fromX > this->maxSizeWorldGrid.x)
        this->fromX = maxSizeWorldGrid.x;

    this->toX = gameCharacter->getGridPosition(this->gridSizeI).x + 3;
    if(this->toX <0 )
        this->toX = 0;
    else if (this->toX > this->maxSizeWorldGrid.x)
        this->toX = maxSizeWorldGrid.x;

    this->fromY = gameCharacter->getGridPosition(this->gridSizeI).y - 1;
    if(this->fromY < 0)
        this->fromY = 0;
    else if (this->fromY > this->maxSizeWorldGrid.y)
        this->fromY = maxSizeWorldGrid.y;

    this->toY = gameCharacter->getGridPosition(this->gridSizeI).y + 3;
    if(this->toY < 0)
        this->toY = 0;
    else if (this->toY > this->maxSizeWorldGrid.y)
        this->toY = maxSizeWorldGrid.y;

    for(int x = this->fromX; x < this->toX; x++){
        for(int y = this->fromY; y < this->toY; y++) {
            sf::FloatRect heroBounds = gameCharacter->getGlobalBounds();
            sf::FloatRect wallBounds = this->map[x][y][this->layer]->getGlobalBounds();
            sf::FloatRect nextPositionBounds = gameCharacter->getNextPositionBounds(dt);
            if(this->map[x][y][this->layer]->getCollision() &&
                    this->map[x][y][this->layer]->intersects(nextPositionBounds)){
                if(heroBounds.top < wallBounds.top
                    && heroBounds.top + heroBounds.height < wallBounds.top + wallBounds.height
                    && heroBounds.left < wallBounds.left + wallBounds.width
                    && heroBounds.left + heroBounds.width > wallBounds.left
                    ){
                    gameCharacter->stopVelocityY();
                    gameCharacter->setPosition(heroBounds.left, wallBounds.top - heroBounds.height);
                }
                else if(heroBounds.top > wallBounds.top
                   && heroBounds.top + heroBounds.height > wallBounds.top + wallBounds.height
                   && heroBounds.left < wallBounds.left + wallBounds.width
                   && heroBounds.left + heroBounds.width > wallBounds.left
                        ){
                    gameCharacter->stopVelocityY();
                    gameCharacter->setPosition(heroBounds.left, wallBounds.top + wallBounds.height);
                }
                if(heroBounds.left < wallBounds.left
                   && heroBounds.left + heroBounds.width < wallBounds.left + wallBounds.width
                   && heroBounds.top < wallBounds.top + wallBounds.height
                   && heroBounds.top + heroBounds.height > wallBounds.top
                        ){
                    gameCharacter->stopVelocityX();
                    gameCharacter->setPosition(wallBounds.left - heroBounds.width, heroBounds.top);
                }
                else if(heroBounds.left > wallBounds.left
                        && heroBounds.left + heroBounds.width > wallBounds.left + wallBounds.width
                        && heroBounds.top < wallBounds.top + wallBounds.height
                        && heroBounds.top + heroBounds.height > wallBounds.top
                        ){
                    gameCharacter->stopVelocityX();
                    gameCharacter->setPosition(wallBounds.left + wallBounds.width, heroBounds.top);
                }
            }
        }
    }
}
