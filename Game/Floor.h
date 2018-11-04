//
// Created by Gustavo Sanchez on 10/26/18.
//

#ifndef TEXTADVENTURE_FLOOR_H
#define TEXTADVENTURE_FLOOR_H

#include <iostream>
#include <list>
#include "Component.h"
#include "../External/tinyxml2.h"


class Floor: public Component {
public:
    int getId() { return id; };
    void load(tinyxml2::XMLElement* element);
    static Floor* findById(int id);
    void display() override;
};


#endif //TEXTADVENTURE_FLOOR_H
