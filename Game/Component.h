//
// Created by Gustavo Sanchez on 11/2/18.
//

#ifndef TEXTADVENTURE_COMPONENT_H
#define TEXTADVENTURE_COMPONENT_H

#include <iostream>
#include "../External/tinyxml2.h";
#include "../Engine/RenderSystem.h"

class Component {
public:
    int id;
    std::string name;
    std::string description;
    Engine::RenderSystem* renderSystem;
    int attackCounter = 0;
    int moveCounter = 0;
    int takeCounter = 0;
    virtual void load(tinyxml2::XMLElement *element);
    Component();
    ~Component();
    virtual void display();
};


#endif //TEXTADVENTURE_COMPONENT_H
