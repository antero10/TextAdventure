//
// Created by Gustavo Sanchez on 10/29/18.
//

#include "Config.h"
#include "Item.h"
#include "Gun.h"
#include "Room.h"
#include "../Engine/FileSystem.h"


Item::Item() {

}

Item::~Item() {
    std::cout << "bye" << std::endl;
}


void Item::load(tinyxml2::XMLElement* element) {
    Component::load(element);
    if (element != nullptr) {
        tinyxml2::XMLElement* damageElement = element->FirstChildElement("Damage");
        if (damageElement != nullptr) {
            damage = std::stoi(damageElement->GetText());
        }
    }
}

Item *Item::findByName(std::string name, std::vector<Item*> items) {
    if (items.size() > 0) {
        for (int i = 0; i <= items.size() - 1; ++i) {
            Item* item = items[i];
            if (item->name == name) {
                return item;
            }
        }
    }
    return nullptr;
}

Item *Item::getItemByElement(tinyxml2::XMLElement *element) {
    if (element != nullptr) {
        std::string type = element->FirstChildElement("Type")->GetText();
        if (type == "Gun") {
            Item* gun = new Gun();
            gun->load(element);
            return gun;
        }
    }
    return nullptr;
}

void Item::display() {
    Component::display();
}

void Item::use() {
    renderSystem->RenderText("Using Item: " + name, "purple");

}
