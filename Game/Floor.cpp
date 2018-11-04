//
// Created by Gustavo Sanchez on 10/26/18.
//

#include "Floor.h"
#include "Config.h"
#include "../Engine/FileSystem.h"

void Floor::load(tinyxml2::XMLElement* element) {
    tinyxml2::XMLElement* idElement = element->FirstChildElement("Id");
    if (idElement != nullptr) {
        id = std::stoi(idElement->GetText());
    }

    tinyxml2::XMLElement* nameElement = element->FirstChildElement("Name");
    if (nameElement  != nullptr) {
        name = nameElement->GetText();
    }

    tinyxml2::XMLElement* descriptionElement = element->FirstChildElement("Description");
    if (descriptionElement != nullptr) {
        description = descriptionElement->GetText();
    }

}

Floor *Floor::findById(int id) {

    Engine::FileSystem::instance().loadXML(Config::instance().GAME_SETTINGS_FILE);
    tinyxml2::XMLElement* gameSettings =  Engine::FileSystem::instance().doc.FirstChildElement("GameSettings");
    tinyxml2::XMLElement* floors =  gameSettings->FirstChildElement("Floors");
    if (gameSettings != nullptr && floors != nullptr) {
        for(tinyxml2::XMLElement* floor = floors->FirstChildElement("Floor"); floor != NULL; floor = floor->NextSiblingElement("Floor"))
        {
            Floor* floorObject = new Floor();
            floorObject->load(floor);
            if (floorObject->getId() == id) {
                return floorObject;
            }
        }
    }

    return nullptr;


}

void Floor::display() {
    Component::display();
}
