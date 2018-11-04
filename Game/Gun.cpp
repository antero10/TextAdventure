//
// Created by Gustavo Sanchez on 11/1/18.
//

#include "Gun.h"
Gun::Gun() {
    name = "Gun";
    damage = 50;
}

Gun::~Gun() {

}

void Gun::load(tinyxml2::XMLElement *element) {
    Item::load(element);
    if (element != nullptr) {
        tinyxml2::XMLElement* ammoElement = element->FirstChildElement("Ammo");
        if (ammoElement) {
            ammo = std::stoi(ammoElement->GetText());
        }

    }
}

void Gun::use() {
    renderSystem->RenderText("PAM PAM!", "cyan");
}

void Gun::display() {
    Item::display();
}

