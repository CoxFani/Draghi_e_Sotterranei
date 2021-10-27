//
// Created by alpacox on 25/03/21.
//

#include "precompiler.h"
#include "TileMap.h"

TileMap::TileMap(float gridSize, unsigned  width, unsigned  height, std::string texture_file) {
    this->gridSizeF = gridSize;
    this->gridSizeU = static_cast<unsigned>(this->gridSizeF);
    this->maxSize.x = width;
    this->maxSize.y = height;
    this->layers = 1;
    this->textureFile = texture_file;

    this->map.resize(this->maxSize.x, std::vector< std::vector<Tile*> >());
    for(size_t x = 0; x < this->maxSize.x; x++){

        for(size_t y = 0; y < this->maxSize.y; y++) {
            this->map[x].resize(this->maxSize.y, std::vector<Tile*>());

            for (size_t z = 0; z < this->layers; z++) {
                this->map[x][y].resize(this->layers, nullptr);

            }
        }
    }
    if(!this->tileSheet.loadFromFile(textureFile))
        std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";
}

TileMap::~TileMap() {
    this->clear();
}

void TileMap::update() {

}

void TileMap::render(sf::RenderTarget &target) {

    for(auto &x : this->map){
        for(auto &y : x){
            for(auto *z : y){
                if(z != nullptr)
                z->render(target);
            }
        }
    }
}

void TileMap::addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect, const bool& collision, const short& type) {

    if(x < this->maxSize.x && x >= 0 &&
       y < this->maxSize.y && y >= 0 &&
       z < this->layers && z >= 0){

        if(this->map[x][y][z] == nullptr){

            this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->tileSheet,  texture_rect, collision, type);
            std::cout <<"DEBUG: ADDED A TILE!" << "\n";
        }
    }
}

void TileMap::removeTile(const unsigned x, const unsigned y, const unsigned z) {

    if(x < this->maxSize.x && x >= 0 &&
       y < this->maxSize.y && y >= 0 &&
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

        out_file << this->maxSize.x << " " << this->maxSize.y << "\n"
             << this->gridSizeU << "\n"
             << this->layers << "\n"
             << this->textureFile << "\n";

        for(size_t x = 0; x < this->maxSize.x; x++){
            for(size_t y = 0; y < this->maxSize.y; y++) {
                for (size_t z = 0; z < this->layers; z++) {
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
        sf::Vector2u  size;
        unsigned gridSize = 0;
        unsigned layers = 0;
        std::string texture_file = "";
        unsigned x = 0;
        unsigned y = 0;
        unsigned z = 0;
        unsigned trX = 0;
        unsigned trY = 0;
        bool collision = false;
        short type = 0;
        in_file >> size.x >> size.y >> gridSize >> layers >> texture_file;

        this->gridSizeF = static_cast<float>(gridSize);
        this->gridSizeU = gridSize;
        this->maxSize.x = size.x;
        this->maxSize.y = size.y;
        this->layers = layers;
        this->textureFile = texture_file;

        this->clear();

        this->map.resize(this->maxSize.x, std::vector< std::vector<Tile*> >());
        for(size_t x = 0; x < this->maxSize.x; x++){
            for(size_t y = 0; y < this->maxSize.y; y++) {
                this->map[x].resize(this->maxSize.y, std::vector<Tile*>());
                for (size_t z = 0; z < this->layers; z++) {
                    this->map[x][y].resize(this->layers, nullptr);
                }
            }
        }
        if(!this->tileSheet.loadFromFile(textureFile))
            std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";
        while(in_file >> x >> y >> z >> trX >> trY >> collision >> type){
            this->map[x][y][z] = new Tile(x, y, this->gridSizeF, this->tileSheet, sf::IntRect(trX, trY, gridSizeU, gridSizeU), collision, type);
        }
    }
    else{
        std::cout << "ERROR::TILEMAP::COULD NOT LOAD FROM FILE " << file_name << "\n";
    }

    in_file.close();
}

void TileMap::clear() {
    for(size_t x = 0; x < this->maxSize.x; x++){
        for(size_t y = 0; y < this->maxSize.y; y++) {
            for (size_t z = 0; z < this->layers; z++) {
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
