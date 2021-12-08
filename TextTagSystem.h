//
// Created by gabriele on 06/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
#define DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H

enum TAGTYPES { DEFAULT_TAG, NEGATIVE_TAG, POSITIVE_TAG, EXPERIENCE_TAG, ENVIROMENTAL_TAG};

class TextTagSystem {
public:
    TextTagSystem(std::string font_file);
    virtual ~TextTagSystem();

    void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const std::string str, const std::string prefix = "", const std::string postfix = "");
    void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const int i, const std::string prefix = "", const std::string postfix = "");
    void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const float f, const std::string prefix = "", const std::string postfix = "");

    void update(const float &dt);
    void render(sf::RenderTarget &target);

private:
    class TextTag {
    public:
        TextTag(sf::Font& font, std::string text,
                float pos_x, float pos_y,
                float dir_x, float dir_y,
                sf::Color color,
                unsigned char_size,
                float lifetime, float speed);

        TextTag(TextTag* tag, float pos_x, float pos_y, std::string str);

        ~TextTag();

        const bool isExpired() const;

        void update(const float& dt);
        void render(sf::RenderTarget& target);

    private:
        sf::Text text;
        float dirX;
        float dirY;
        float lifetime;
        float speed;

    };

    void initVariables();
    void initFonts(std::string font_file);
    void initTagTemplates();

    sf::Font font;
    std::map<unsigned , TextTag*> tagTemplates;
    std::vector<TextTag*> tags;
};


#endif //DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
