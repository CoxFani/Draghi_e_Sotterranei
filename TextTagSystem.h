//
// Created by gabriele on 06/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
#define DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H

enum TAGTYPES { DEFAULT_TAG, NEGATIVE_TAG, EXPERIENCE_TAG, ACHIEVEMENT_TAG};

class TextTagSystem {
public:
    explicit TextTagSystem(std::string font_file);
    virtual ~TextTagSystem();

    void addTextTag( unsigned tag_type,  float pos_x,  float pos_y,  std::string str,  std::string prefix = "",  std::string postfix = "");
    void addTextTag( unsigned tag_type,  float pos_x,  float pos_y,  int i,  std::string prefix = "",  std::string postfix = "");
    void addTextTag( unsigned tag_type,  float pos_x,  float pos_y,  float f,  std::string prefix = "",  std::string postfix = "");

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
                float lifetime, bool reverse, float speed, float acceleration, int fade_value);

        TextTag(TextTag* tag, float pos_x, float pos_y, std::string str);

        virtual ~TextTag();

        bool isExpired() const;

        void update(const float& dt);
        void render(sf::RenderTarget& target);

    private:
        sf::Text text;
        float dirX;
        float dirY;
        float lifetime;
        bool reverse;
        float speed;
        float acceleration;
        sf::Vector2f velocity;
        int fadeValue;

    };

    void initVariables();
    void initTagTemplates();

    sf::Font font;
    std::map<unsigned, TextTag*> tagTemplates;
    std::vector<TextTag*> tags;
};


#endif //DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
