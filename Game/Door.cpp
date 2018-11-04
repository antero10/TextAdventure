//
// Created by Gustavo Sanchez on 10/26/18.
//

#include "Door.h"


Door::Door() {

}

Door::~Door() {

}


void Door::load(tinyxml2::XMLElement* element) {
    tinyxml2::XMLElement* directionElement = element->FirstChildElement("Direction");
    if (directionElement) {
        direction = directionElement->GetText();
        remove_if(direction.begin(), direction.end(), isspace);

    }

    tinyxml2::XMLElement* fromElement = element->FirstChildElement("From");
    if (fromElement) {
        from = std::stoi(fromElement->GetText());
    }

    tinyxml2::XMLElement* toElement = element->FirstChildElement("To");
    if (toElement) {
        to = std::stoi(toElement->GetText());
    }

}
