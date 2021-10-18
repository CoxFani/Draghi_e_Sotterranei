//
// Created by alpacox on 15/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GRAPHICSSETTINGS_H
#define DRAGHI_E_SOTTERRANEI_GRAPHICSSETTINGS_H


class GraphicsSettings{
public:
    GraphicsSettings();

    std::string title;
    sf::VideoMode resolution;
    bool fullscreen;
    bool verticalSync;
    unsigned frameRateLimit;
    sf::ContextSettings contextSettings;
    std::vector<sf::VideoMode> videoModes;

    void saveToFile(const std::string path);

    void loadFromFile(const std::string path);

};



#endif //DRAGHI_E_SOTTERRANEI_GRAPHICSSETTINGS_H
