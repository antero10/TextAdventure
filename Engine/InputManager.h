//
// Created by Gustavo Sanchez on 10/29/18.
//

#ifndef TEXTADVENTURE_INPUTMANAGER_H
#define TEXTADVENTURE_INPUTMANAGER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
namespace  Engine {
    class InputManager {
    public:
        std::string loadInput(std::string waitingSymbol = "");
    };
}



#endif //TEXTADVENTURE_INPUTMANAGER_H
