//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_DOOR_H
#define TEXTADVENTURE_DOOR_H

#include <iostream>
#include "../External/tinyxml2.h"

class Door {

public:
    int from;
    int to;
    std::string direction;
    bool isOpen;
    void load(tinyxml2::XMLElement* element);
    Door();
    ~Door();

};


#endif //TEXTADVENTURE_DOOR_H
