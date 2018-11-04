//
// Created by Gustavo Sanchez on 11/2/18.
//

#include "GameEngineAnalytics.h"
#include "../Game/Config.h";

Engine::GameEngineAnalytics::GameEngineAnalytics() {
}

Engine::GameEngineAnalytics::~GameEngineAnalytics() {
}

void Engine::GameEngineAnalytics::saveAction(std::string action, std::string value) {
    tinyxml2::XMLElement* element;

    element = FileSystem::instance().analytics.FirstChildElement("Actions");

    if (element == nullptr) {
        element = FileSystem::instance().createElement("Actions");
    }

    FileSystem::instance().createElementChild(element, action.c_str(), value);
    FileSystem::instance().createXML(Config::instance().GAME_ANALYTICS_FILE);




}
