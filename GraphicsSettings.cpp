//
// Created by alpacox on 15/10/21.
//

#include "precompiler.h"
#include "GraphicsSettings.h"

GraphicsSettings::GraphicsSettings() {
    title = "DEFAULT";
    resolution = sf:: VideoMode::getDesktopMode();
    fullscreen = false;
    verticalSync = false;
    frameRateLimit = 120;
    contextSettings.antialiasingLevel = 0;
    videoModes = sf::VideoMode::getFullscreenModes();
}

void GraphicsSettings::saveToFile(const std::string path) {
    std::ofstream ofs(path);

    if (ofs.is_open()){
        ofs << title;
        ofs << resolution.width << " " << this->resolution.height;
        ofs << fullscreen;
        ofs << frameRateLimit;
        ofs << verticalSync;
        ofs << contextSettings.antialiasingLevel;
    }

    ofs.close();
}

void GraphicsSettings::loadFromFile(const std::string path) {
    std::ifstream ifs(path);

    if (ifs.is_open()){
        std::getline(ifs, title);
        ifs >> resolution.width >> resolution.height;
        ifs >> fullscreen;
        ifs >> frameRateLimit;
        ifs >> verticalSync;
        ifs >> contextSettings.antialiasingLevel;
    }

    ifs.close();
}
