//
// Created by gabriele on 06/12/21.
//

#include "precompiler.h"
#include "TextTagSystem.h"

TextTagSystem::TextTagSystem(std::string font_file) {
    if(!this->font.loadFromFile(font_file))
        std::cout << "ERROR::TEXTTAGSYSTEM::CONSTRUCTOR::Failed to load font" << font_file << "\n";

    this->initTagTemplates();
    this->initVariables();

}

TextTagSystem::~TextTagSystem() {
    for(auto *tag : this->tags){
        delete tag;
    }

    for(auto &tag : this->tagTemplates){
        delete tag.second;
    }
}

void TextTagSystem::initVariables() {

}

void TextTagSystem::initFonts(std::string font_file) {
    if(!this->font.loadFromFile(font_file))
        std::cout << "ERROR::TEXTTAGSYSTEM::CONSTRUCTOR::Failed to load font" << font_file << "\n";
}

void TextTagSystem::initTagTemplates() {
    this->tagTemplates[DEFAULT_TAG] = new TextTag(this->font, "", 0.f, 0.f, 0.f, -1.f, sf::Color::White, 20, 50.f, 150.f);
    this->tagTemplates[NEGATIVE_TAG] = new TextTag(this->font, "", 0.f, 0.f, 0.f, -1.f, sf::Color::Red, 20, 50.f, 200.f);
    this->tagTemplates[EXPERIENCE_TAG] = new TextTag(this->font, "", 0.f, 0.f, 0.f, -1.f, sf::Color::Cyan, 25, 70.f, 150.f);


}

void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const std::string str) {
    this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, str));
}

void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const int i) {
    std::stringstream  ss;
    ss << i;
    this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const float f) {
    std::stringstream  ss;
    ss << f;
    this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void TextTagSystem::update(const float &dt) {
    for(size_t i = 0; i < this->tags.size(); ++i) {
        this->tags[i]->update(dt);
        if(this->tags[i]->isExpired()){
            delete this->tags[i];
            this->tags.erase(this->tags.begin() + i);
        }
    }
}

void TextTagSystem::render(sf::RenderTarget &target) {
    for(auto &tag : this->tags){
        tag->render(target);
    }
}

/*****************************  TEXT TAG  *****************************/

TextTagSystem::TextTag::TextTag(sf::Font &font, std::string text,
                                float pos_x, float pos_y,
                                float dir_x, float dir_y,
                                sf::Color color,
                                unsigned int char_size,
                                float lifetime, float speed) {
    this->text.setFont(font);
    this->text.setPosition(pos_x, pos_y);
    this->text.setFillColor(color);
    this->text.setCharacterSize(char_size);
    this->text.setString(text);

    this->dirX = dir_x;
    this->dirY = dir_y;
    this->lifetime = lifetime;
    this->speed = speed;
}

TextTagSystem::TextTag::TextTag(TextTagSystem::TextTag* tag, float pos_x, float pos_y, std::string str) {
    this->text = tag->text;
    this->text.setString(str);
    this->text.setPosition(pos_x, pos_y);

    this->dirX = tag->dirX;
    this->dirY = tag->dirY;
    this->lifetime = tag->lifetime;
    this->speed = tag->speed;
}

TextTagSystem::TextTag::~TextTag() {

}

const bool TextTagSystem::TextTag::isExpired() const {
    return this->lifetime <= 0.f;
}

void TextTagSystem::TextTag::update(const float &dt) {
    if(this->lifetime > 0.f){
        this->lifetime -= 100.f * dt;
        this->text.move(this->dirX * this->speed * dt, this->dirY * this->speed * dt);
    }
}

void TextTagSystem::TextTag::render(sf::RenderTarget &target) {
    target.draw(this->text);
}




