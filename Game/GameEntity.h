//
// Created by Gustavo Sanchez on 11/2/18.
//

#ifndef TEXTADVENTURE_GAMEENTITY_H
#define TEXTADVENTURE_GAMEENTITY_H

#include <iostream>
#include "Action.h"
#include "Component.h"

class GameEntity: public Component {
public:
    int health = 0;
    virtual void execute(Action* action) = 0;
    virtual void attack(GameEntity* gameEntity) = 0;
    virtual bool move(std::string direction = "") = 0;
    virtual bool isAlive();
    virtual void takeDamage(int damage);
    virtual int getHealth() { return health; };
    virtual void display() = 0;
    virtual void setHealth(int newHealth);
};


#endif //TEXTADVENTURE_GAMEENTITY_H
