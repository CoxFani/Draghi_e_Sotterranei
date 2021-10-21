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

    for(size_t x = 0; x < this->maxSize.x; x++){

        for(size_t y = 0; y < this->maxSize.y; y++) {

            for (size_t z = 0; z < this->layers; z++) {

                delete this->map[x][y][z];
            }
        }
    }
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

void TileMap::addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect) {

    if(x < this->maxSize.x && x >= 0 &&
       y < this->maxSize.y && y >= 0 &&
       z < this->layers && z >= 0){

        if(this->map[x][y][z] == nullptr){

            this->map[x][y][z] = new Tile(x * this->gridSizeF, y * gridSizeF, this->gridSizeF, this->tileSheet,  texture_rect);
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
 * gridPos x y, Texture rect x y
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

                out_file << 1 << 1 << 2 << 3 << 5 << " ";
                //out_file <<  this->map[x][y][z];
            }
        }
    }


}
else{
    std::cout << "ERROR::TILEMAP::COULD NOT SAVE TO FILE " << file_name << "\n";
}

out_file.close();
}

void TileMap::LoadFromFile(const std::string file_name) {

}

