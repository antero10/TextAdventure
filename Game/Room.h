//
// Created by Gustavo Sanchez on 10/26/18.
//

#ifndef TEXTADVENTURE_ROOM_H
#define TEXTADVENTURE_ROOM_H

#include <iostream>
#include <vector>
#include "Door.h"
#include "GameEntity.h"
#include "Component.h"
#include "Item.h"

#include "../External/tinyxml2.h"

class Room: public Component {
private:
    std::vector<Door*> doors;
    std::vector<GameEntity*> enemies;
    std::vector<Item*> items;
public:
    int getId() { return id; }
    std::string getDescription() { return description; }
    std::vector<Door*> getDoors() { return doors; };
    std::vector<GameEntity*> getEnemies() { return enemies; };
    std::vector<Item*> getItems() {return items;}
    void removeEnemy(GameEntity* enemy);
    void removeItem(Item* item);
    void load(tinyxml2::XMLElement* element);
    static Room* findById(int id);
    void display() override;
    GameEntity* getEnemy(GameEntity* gameEntity);
    GameEntity* getEnemyByName(std::string name);
    Room();
    ~Room();
};


#endif TEXTADVENTURE_ROOM_H
