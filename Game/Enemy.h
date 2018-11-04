//
// Created by Gustavo Sanchez on 11/2/18.
//

#ifndef TEXTADVENTURE_ENEMY_H
#define TEXTADVENTURE_ENEMY_H

#include <iostream>
#include <vector>
#include "../External/tinyxml2.h"
#include "GameEntity.h"

class Enemy: public GameEntity {
protected:
    int damage = 10;
    int enemyAttackCounter = 0;
public:
    Enemy();
    ~Enemy();
    void execute(Action* action) override;
    void attack(GameEntity* gameEntity) override;
    void load(tinyxml2::XMLElement* element);
    void display() override;
    static Enemy* getEnemyByElement(tinyxml2::XMLElement* element);

};


#endif //TEXTADVENTURE_ENEMY_H
