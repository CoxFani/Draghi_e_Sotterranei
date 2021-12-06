//
// Created by gabriele on 06/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
#define DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H


class TextTagSystem {
public:
    TextTagSystem();
    virtual ~TextTagSystem();

    void addTextTag(TextTag* text_tag);
    void removeTextTag();

    void update(const float &dt);
    void render(sf::RenderTarget *target);

private:
    class TextTag {
    public:

    };
};


#endif //DRAGHI_E_SOTTERRANEI_TEXTTAGSYSTEM_H
