//
// Created by Gustavo Sanchez on 11/2/18.
//

#ifndef TEXTADVENTURE_ZOMBIE_H
#define TEXTADVENTURE_ZOMBIE_H

#include <iostream>
#include "Enemy.h"

class Zombie: public Enemy {
public:
    Zombie();
    ~Zombie();
    void execute(Action* action) override;
    void load(tinyxml2::XMLElement* element) override;
    bool move(std::string direction = "") override;
    void attack(GameEntity* gameEntity) override;
    void display() override;
};

#endif //TEXTADVENTURE_ZOMBIE_H
