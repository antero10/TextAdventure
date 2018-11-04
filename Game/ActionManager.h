//
// Created by Gustavo Sanchez on 10/31/18.
//

#ifndef TEXTADVENTURE_ACTIONMANAGER_H
#define TEXTADVENTURE_ACTIONMANAGER_H

#include <iostream>
#include <map>
#include "Action.h"
class ActionManager {
public:
    ActionManager();
    ~ActionManager();
    Action* getAction(std::string action);
    std::string loadInput(std::string waitingSymbol);
};


#endif //TEXTADVENTURE_ACTIONMANAGER_H
