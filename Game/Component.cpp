//
// Created by Gustavo Sanchez on 11/2/18.
//

#include "Component.h"

Component::Component() {
  renderSystem = new Engine::RenderSystem();
}

Component::~Component() {
    delete renderSystem;
}

void Component::display() {
    renderSystem->RenderText(description, "blue");
}

void Component::load(tinyxml2::XMLElement *element) {

    tinyxml2::XMLElement* idElement = element->FirstChildElement("Id");
    if (idElement != nullptr) {
        id = std::stoi(idElement->GetText());
    }

    tinyxml2::XMLElement* nameElement = element->FirstChildElement("Name");
    if (nameElement != nullptr) {
        name = nameElement->GetText();
    }

    tinyxml2::XMLElement* descriptionElement = element->FirstChildElement("Description");
    if (descriptionElement != nullptr) {
        description = descriptionElement->GetText();
    }

}
