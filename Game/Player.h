//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_PLAYER_H
#define TEXTADVENTURE_PLAYER_H

#include <iostream>
#include <vector>
#include "Floor.h"
#include "Action.h"
#include "Item.h"
#include "GameEntity.h"
#include "Room.h"

class Player: public GameEntity {
protected:
    Room* currentRoom;
    Floor* currentFloor;
    std::vector<Item*> inventory;
public:
    Player();
    ~Player();
    void execute(Action* action) override;
    void attack(GameEntity* gameEntity) override;
    void take(std::string itemName);
    bool move(std::string direction) override;
    Room* getCurrentRoom(){ return currentRoom; };
    Floor* getCurrentFloor(){ return currentFloor; };
    void setRoom(Room* room);
    void setFloor(Floor* floor);
    void display() override;
    void use(Item* item);
    void info();
    Item* getItemFromInventory(std::string itemName);
    std::vector<Item*> getItems();
};


#endif //TEXTADVENTURE_PLAYER_H
