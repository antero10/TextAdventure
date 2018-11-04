//
// Created by Gustavo Sanchez on 11/1/18.
//

#ifndef TEXTADVENTURE_GUN_H
#define TEXTADVENTURE_GUN_H

#include "Item.h"
#include "../External/tinyxml2.h"
class Gun: public Item {
private:
    int ammo = 0;
public:
    Gun();
    ~Gun();
    void load(tinyxml2::XMLElement* element) override;
    void use() override;
    void display() override;
};


#endif //TEXTADVENTURE_GUN_H
