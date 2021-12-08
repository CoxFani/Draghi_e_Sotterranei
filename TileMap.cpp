//
// Created by alpacox on 25/03/21.
//

#include "precompiler.h"
#include "TileMap.h"

TileMap::TileMap(float gridSize, int  width, int  height, std::string texture_file) {
    this->gridSizeF = gridSize;
    this->gridSizeI = static_cast<unsigned>(this->gridSizeF);
    this->maxSizeWorldGrid.x = width;
    this->maxSizeWorldGrid.y = height;
    this->maxSizeWorldF.x = static_cast<float>(width) * gridSize;
    this->maxSizeWorldF.y = static_cast<float>(height) * gridSize;
    this->layers = 1; //layers<>layer
    this->textureFile = texture_file;
    this->fromX = 0;
    this->toX = 0;
    this->fromY = 0;
    this->toY = 0;
    this->layer = 0; //layer<>layers

    this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector< std::vector< Tile*> > >());
    for(int x = 0; x < this->maxSizeWorldGrid.x; x++){
        for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
            this->map[x].resize(this->maxSizeWorldGrid.y, std::vector< std::vector < Tile*> >());
            for (int z = 0; z < this->layers; z++)
                this->map[x][y].resize(this->layers, std::vector<Tile*>());
        }
    }
    if(!this->tileSheet.loadFromFile(textureFile))
        std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";

    this->collisionBox.setSize(sf::Vector2f(gridSize, gridSize));
    this->collisionBox.setFillColor(sf::Color(255, 0, 0, 50));
    this->collisionBox.setOutlineColor(sf::Color::Red);
    this->collisionBox.setOutlineThickness(-1.f);
}

TileMap::TileMap(const std::string file_name) {
    this->fromX = 0;
    this->toX = 0;
    this->fromY = 0;
    this->toY = 0;
    this->layer = 0; //layer<>layers

    this->loadFromFile(file_name);

    this->collisionBox.setSize(sf::Vector2f(this->gridSizeF, this->gridSizeF));
    this->collisionBox.setFillColor(sf::Color(255, 0, 0, 50));
    this->collisionBox.setOutlineColor(sf::Color::Red);
    this->collisionBox.setOutlineThickness(-1.f);
}

TileMap::~TileMap() {
    this->clear();
}

void TileMap::clear() {
    if(!this->map.empty()) {
        for (int x = 0; x < this->map.size(); x++) {
            for (int y = 0; y < this->map[x].size(); y++) {
                for (int z = 0; z < this->map[x][y].size(); z++) {
                    for (int k = 0; k < this->map[x][y][z].size(); k++) {
                        delete this->map[x][y][z][k];
                        this->map[x][y][z][k] = nullptr;
                    }
                    this->map[x][y][z].clear();
                }
                this->map[x][y].clear();
            }
            this->map[x].clear();
        }
        this->map.clear();
    }
    //std::cout << this->map.size() << "\n";
}

const bool TileMap::tileEmpty(const int x, const int y, const int z) const{
    if(x >= 0 && x < this->maxSizeWorldGrid.x &&
       y >= 0 && y < this->maxSizeWorldGrid.y &&
       z >= 0 && z < this->layers)
        return this->map[x][y][z].empty();
    return false;
}

const sf::Texture *TileMap::getTileSheet() const{
    return &this->tileSheet;
}

const int TileMap::getLayerSize(const int x, const int y, const int layer) const{
    if(x >= 0 && x <static_cast<int>(this->map.size())){
        if(y >= 0 && y <static_cast<int>(this->map[x].size())){
            if(layer >= 0 && layer <static_cast<int>(this->map[x][y].size())){
                return this->map[x][y][layer].size();
            }
        }
    }
    return -1;
}

const sf::Vector2i &TileMap::getMaxSizeGrid() const {
    return this->maxSizeWorldGrid;
}

const sf::Vector2f &TileMap::getMaxSizeF() const {
    return this->maxSizeWorldF;
}

void TileMap::addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type) {
    if(x < this->maxSizeWorldGrid.x && x >= 0 &&
       y < this->maxSizeWorldGrid.y && y >= 0 &&
       z < this->layers && z >= 0){

        this->map[x][y][z].push_back(new RegularTile(type, x, y, this->gridSizeF, this->tileSheet, texture_rect, collision));


        //std::cout <<"DEBUG: ADDED A TILE!" << "\n";
    }
}

void TileMap::addTile(const int x, const int y, const int z, const sf::IntRect &texture_rect,
                      const int enemy_type, const int enemy_amount, const int enemy_tts, const int enemy_md) {

    if(x < this->maxSizeWorldGrid.x && x >= 0 &&
       y < this->maxSizeWorldGrid.y && y >= 0 &&
       z < this->layers && z >= 0){

        this->map[x][y][z].push_back(new EnemySpawnerTile(x, y, this->gridSizeF, this->tileSheet, texture_rect,
                                                          enemy_type, enemy_amount, enemy_tts, enemy_md));
    }


}

void TileMap::removeTile(const int x, const int y, const int z, const int type) {
    if(x < this->maxSizeWorldGrid.x && x >= 0 &&
       y < this->maxSizeWorldGrid.y && y >= 0 &&
       z < this->layers && z >= 0){
        if(!this->map[x][y][z].empty()){
            if(type >= 0){
                if(this->map[x][y][z].back()->getType() == type) {
                    delete this->map[x][y][z][this->map[x][y][z].size() - 1];
                    this->map[x][y][z].pop_back();
                    //std::cout << "DEBUG: REMOVED A TILE!" << "\n";
                }
            }
            else{
                delete this->map[x][y][z][this->map[x][y][z].size()-1];
                this->map[x][y][z].pop_back();
                //std::cout <<"DEBUG: REMOVED A TILE!" << "\n";
            }
        }
    }
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
    * type
    * gridPos x y layer
    * Texture rect x y
    * collision
    * tile_specific..
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
                    if(!this->map[x][y][z].empty()) {
                        for(int k = 0; k < this->map[x][y][z].size(); k++){
                            out_file << x << " " << y << " " << z << " " <<
                                     this->map[x][y][z][k]->getAsString()
                                     << " ";
                        }
                    }
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
        sf::Vector2i  size;
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
        this->maxSizeWorldF.x = static_cast<float>(size.x * gridSize);
        this->maxSizeWorldF.y = static_cast<float>(size.y * gridSize);
        this->layers = layers;
        this->textureFile = texture_file;

        this->clear();

        this->map.resize(this->maxSizeWorldGrid.x, std::vector< std::vector< std::vector< Tile*> > >());
        for(int x = 0; x < this->maxSizeWorldGrid.x; x++){
            for(int y = 0; y < this->maxSizeWorldGrid.y; y++) {
                this->map[x].resize(this->maxSizeWorldGrid.y, std::vector< std::vector< Tile*> >());
                for (int z = 0; z < this->layers; z++) {
                    this->map[x][y].resize(this->layers, std::vector< Tile*>());
                }
            }
        }
        if(!this->tileSheet.loadFromFile(textureFile))
            std::cout << "ERROR::TILEMAP::FAILED TO LOAD TILETEXTURESHEET::FILENAME: " << texture_file <<"\n";

        while(in_file >> x >> y >> z >> type){
          if(type == TileTypes::ENEMYSPAWNER){
              //amount, time to spawn, max distance
              int enemy_type = 0;
              int enemy_am = 0;
              int enemy_tts = 0;
              int enemy_md = 0;

              in_file >> trX >> trY >> enemy_type >> enemy_am >> enemy_tts >> enemy_md;

              this->map[x][y][z].push_back(
                      new EnemySpawnerTile(
                              x, y,
                              this->gridSizeF,
                              this->tileSheet,
                              sf::IntRect(trX, trY, this->gridSizeI, this->gridSizeI),
                              enemy_type,
                              enemy_am,
                              enemy_tts,
                              enemy_md
                      )
              );

          }
          else{
              in_file >> trX >> trY >> collision;

              this->map[x][y][z].push_back(new RegularTile(
                                                   type,
                                                   x, y,
                                                   this->gridSizeF,
                                                   this->tileSheet,
                                                   sf::IntRect(trX, trY, this->gridSizeI, this->gridSizeI),
                                                   collision
                                           )
              );
          }
        }
    }
    else{
        std::cout << "ERROR::TILEMAP::COULD NOT LOAD FROM FILE " << file_name << "\n";
    }

    in_file.close();
}

void TileMap::updateWorldBoundsCollision(GameCharacter *gameCharacter, const float &dt) {

    //Limiti mappa

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
    else if(gameCharacter->getPosition().y + gameCharacter->getGlobalBounds().height > this->maxSizeWorldF.y) {
        gameCharacter->setPosition( gameCharacter->getPosition().x, this->maxSizeWorldF.y - gameCharacter->getGlobalBounds().height);
        gameCharacter->stopVelocityY();
    }
}

void TileMap::updateTileCollision(GameCharacter *gameCharacter, const float &dt) {

    //Tiles

    this->layer = 0;

    this->fromX = gameCharacter->getGridPosition(this->gridSizeI).x - 1;
    if(this->fromX < 0)
        this->fromX = 0;
    else if(this->fromX > this->maxSizeWorldGrid.x)
        this->fromX = this->maxSizeWorldGrid.x;

    this->toX = gameCharacter->getGridPosition(this->gridSizeI).x + 3;
    if(this->toX < 0)
        this->toX = 0;
    else if(this->toX > this->maxSizeWorldGrid.x)
        this->toX = this->maxSizeWorldGrid.x;

    this->fromY = gameCharacter->getGridPosition(this->gridSizeI).y - 1;
    if(this->fromY < 0)
        this->fromY = 0;
    else if(this->fromY > this->maxSizeWorldGrid.y)
        this->fromY = this->maxSizeWorldGrid.y;

    this->toY = gameCharacter->getGridPosition(this->gridSizeI).y + 3;
    if(this->toY < 0)
        this->toY = 0;
    else if(this->toY > this->maxSizeWorldGrid.y)
        this->toY = this->maxSizeWorldGrid.y;
    //Collisioni

    for(int x = this->fromX; x < this->toX; x++){
        for(int y = this->fromY; y < this->toY; y++) {
            for (int k = 0; k < this->map[x][y][this->layer].size(); k++) {

                sf::FloatRect heroBounds = gameCharacter->getGlobalBounds();
                sf::FloatRect wallBounds = this->map[x][y][this->layer][k]->getGlobalBounds();
                sf::FloatRect nextPositionBounds = gameCharacter->getNextPositionBounds(dt);

                if (this->map[x][y][this->layer][k]->getCollision() &&
                    this->map[x][y][this->layer][k]->intersects(nextPositionBounds)) {

                    //Collisione inferiore
                    if (heroBounds.top < wallBounds.top
                        && heroBounds.top + heroBounds.height < wallBounds.top + wallBounds.height
                        && heroBounds.left < wallBounds.left + wallBounds.width
                        && heroBounds.left + heroBounds.width > wallBounds.left
                            ) {
                        gameCharacter->stopVelocityY();
                        gameCharacter->setPosition(heroBounds.left, wallBounds.top - heroBounds.height);
                    }
                        //Collisione superiore
                    else if (heroBounds.top > wallBounds.top
                             && heroBounds.top + heroBounds.height > wallBounds.top + wallBounds.height
                             && heroBounds.left < wallBounds.left + wallBounds.width
                             && heroBounds.left + heroBounds.width > wallBounds.left
                            ) {
                        gameCharacter->stopVelocityY();
                        gameCharacter->setPosition(heroBounds.left, wallBounds.top + wallBounds.height);
                    }

                    //Collisione destra
                    if (heroBounds.left < wallBounds.left
                        && heroBounds.left + heroBounds.width < wallBounds.left + wallBounds.width
                        && heroBounds.top < wallBounds.top + wallBounds.height
                        && heroBounds.top + heroBounds.height > wallBounds.top) {
                        gameCharacter->stopVelocityX();
                        gameCharacter->setPosition(wallBounds.left - heroBounds.width, heroBounds.top);
                    }
                        //Collisione sinistra
                    else if (heroBounds.left > wallBounds.left
                             && heroBounds.left + heroBounds.width > wallBounds.left + wallBounds.width
                             && heroBounds.top < wallBounds.top + wallBounds.height
                             && heroBounds.top + heroBounds.height > wallBounds.top
                            ) {
                        gameCharacter->stopVelocityX();
                        gameCharacter->setPosition(wallBounds.left + wallBounds.width, heroBounds.top);
                    }
                }
            }
        }
    }
}

void TileMap::updateTiles(GameCharacter *gameCharacter, const float &dt,
                          EnemyStrategy &enemyStrategy) {

    //Tiles

    this->layer = 0;

    this->fromX = gameCharacter->getGridPosition(this->gridSizeI).x - 20;
    if(this->fromX < 0)
        this->fromX = 0;
    else if(this->fromX > this->maxSizeWorldGrid.x)
        this->fromX = this->maxSizeWorldGrid.x;

    this->toX = gameCharacter->getGridPosition(this->gridSizeI).x + 21;
    if(this->toX < 0)
        this->toX = 0;
    else if(this->toX > this->maxSizeWorldGrid.x)
        this->toX = this->maxSizeWorldGrid.x;

    this->fromY = gameCharacter->getGridPosition(this->gridSizeI).y - 11;
    if(this->fromY < 0)
        this->fromY = 0;
    else if(this->fromY > this->maxSizeWorldGrid.y)
        this->fromY = this->maxSizeWorldGrid.y;

    this->toY = gameCharacter->getGridPosition(this->gridSizeI).y + 12;
    if(this->toY < 0)
        this->toY = 0;
    else if(this->toY > this->maxSizeWorldGrid.y)
        this->toY = this->maxSizeWorldGrid.y;
    //Collisioni

    for(int x = this->fromX; x < this->toX; x++){
        for(int y = this->fromY; y < this->toY; y++) {
            for (int k = 0; k < this->map[x][y][this->layer].size(); k++) {

                this->map[x][y][this->layer][k]->update();

                if(this->map[x][y][this->layer][k]->getType() == TileTypes::ENEMYSPAWNER){
                    EnemySpawnerTile* es = dynamic_cast<EnemySpawnerTile*>(this->map[x][y][this->layer][k]);
                    if(!es->getSpawned()) {
                        enemyStrategy.createEnemy(MUMMY, x*this->gridSizeF, y*gridSizeF);
                        es->setSpawn(true);
                    }
                }
            }
        }
    }
}

void TileMap::update(GameCharacter *gameCharacter, const float& dt) {


}

void TileMap::render(
        sf::RenderTarget &target,
        const sf::Vector2i& gridPosition,
        sf::Shader* shader,
        const sf::Vector2f heroPosition,
        const bool show_collision
        ) {

        this->layer = 0;

        this->fromX = gridPosition.x - 20;
        if (this->fromX < 0)
            this->fromX = 0;
        else if (this->fromX > this->maxSizeWorldGrid.x)
            this->fromX = this->maxSizeWorldGrid.x;

        this->toX = gridPosition.x + 21;
        if (this->toX < 0)
            this->toX = 0;
        else if (this->toX > this->maxSizeWorldGrid.x)
            this->toX = this->maxSizeWorldGrid.x;

        this->fromY = gridPosition.y - 11;
        if (this->fromY < 0)
            this->fromY = 0;
        else if (this->fromY > this->maxSizeWorldGrid.y)
            this->fromY = this->maxSizeWorldGrid.y;

        this->toY = gridPosition.y + 12;
        if (this->toY < 0)
            this->toY = 0;
        else if (this->toY > this->maxSizeWorldGrid.y)
            this->toY = this->maxSizeWorldGrid.y;

        for (int x = this->fromX; x < this->toX; x++) {
            for (int y = this->fromY; y < this->toY; y++) {
                for (int k = 0; k < this->map[x][y][this->layer].size(); k++){
                    if(this->map[x][y][layer][k]->getType() == TileTypes::FLAVOUR){
                        this->deferredRenderStack.push(this->map[x][y][layer][k]);
                    }
                    else{
                        if(shader)
                            this->map[x][y][this->layer][k]->render(target, shader, heroPosition);
                        else
                            this->map[x][y][this->layer][k]->render(target);

                    }
                    if(show_collision){
                        if (this->map[x][y][this->layer][k]->getCollision()) {
                            this->collisionBox.setPosition(this->map[x][y][this->layer][k]->getPosition());
                            target.draw(this->collisionBox);
                        }
                    }
                    if(this->map[x][y][this->layer][k]->getType() == TileTypes::ENEMYSPAWNER){
                        this->collisionBox.setPosition(this->map[x][y][this->layer][k]->getPosition());
                        //target.draw(this->collisionBox); //TODO commentare per visualizzare enemySpawner
                    }
                }
            }
        }

}

void TileMap::renderDeferred(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f heroPosition) {
    while(!this->deferredRenderStack.empty()){
        if(shader)
            deferredRenderStack.top()->render(target, shader, heroPosition);
        else
            deferredRenderStack.top()->render(target);

        deferredRenderStack.pop();
    }
}

const bool TileMap::checkType(const int x, const int y, const int z, const int type) const {
    return this->map[x][y][this->layer].back()->getType() == type;
}




