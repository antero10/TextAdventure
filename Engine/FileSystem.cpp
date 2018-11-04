//
// Created by Gustavo Sanchez on 10/30/18.
//

#include "FileSystem.h"

Engine::FileSystem::FileSystem() {
}

Engine::FileSystem::~FileSystem() {

}

void Engine::FileSystem::loadXML(const char* fileName) {
    doc.LoadFile(fileName);
}

void Engine::FileSystem::createXML(const char *fileName) {
    analytics.SaveFile(fileName);
}

void Engine::FileSystem::createElementChild(tinyxml2::XMLElement *element, const char* name, std::string value) {

    tinyxml2::XMLElement * newElement;
    newElement = element->FirstChildElement(name);
    if (newElement == nullptr) {
        newElement = analytics.NewElement(name);
        tinyxml2::XMLText * text = analytics.NewText(value.c_str());
        newElement->LinkEndChild(text);
    } else {
        newElement->SetText(value.c_str());
    }
    element->LinkEndChild(newElement);

}

tinyxml2::XMLElement* Engine::FileSystem::createElement(const char* name) {
    tinyxml2::XMLElement * element = analytics.NewElement(name);
    analytics.LinkEndChild(element);
    return element;

}
