//
// Created by Gustavo Sanchez on 10/29/18.
//

#ifndef TEXTADVENTURE_ITEM_H
#define TEXTADVENTURE_ITEM_H

#include <iostream>
#include "GameEntity.h"
#include "Component.h"
#include "../External/tinyxml2.h"
class Item: public Component {
public:
    Item();
    ~Item();
    int damage = 0;
    virtual void load(tinyxml2::XMLElement* element);
    static Item* getItemByElement(tinyxml2::XMLElement* element);
    static Item* findByName(std::string name, std::vector<Item*> items);
    virtual void use();
    void display() override;
};


#endif //TEXTADVENTURE_ITEM_H
