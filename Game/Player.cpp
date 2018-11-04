//
// Created by Gustavo Sanchez on 10/30/18.
//
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <regex>
#include <string>



#include "Player.h"
#include "Game.h"
#include "Config.h"
#include "../Engine/GameEngineAnalytics.h"

Player::Player() {
    name = "Dr Mysterio";
    description = "Player";
    health = 100;
}

Player::~Player() {
    delete currentRoom;
    delete currentFloor;
    std::for_each(inventory.begin(), inventory.end(), [](Item* item) {
        delete item;
    });

}

void Player::execute(Action *action) {
    if (action->name == Config::instance().MOVE_NORTH_ACTION) {
        move(Config::instance().NORTH);
    }
    else if (action->name == Config::instance().MOVE_WEST_ACTION) {
        move(Config::instance().WEST);
    }
    else if (action->name == Config::instance().MOVE_SOUTH_ACTION) {
        move(Config::instance().SOUTH);
    }
    else if(action->name == Config::instance().MOVE_EAST_ACTION) {
        move(Config::instance().EAST);
    }
    else if(action->name == Config::instance().INFO_ACTION) {
        info();
    }
    std::size_t useAction = action->name.find(Config::instance().USE_ACTION);
    if (useAction!=std::string::npos) {
        std::regex rgx(Config::instance().USE_REGEX_ACTION);
        std::smatch matches;
        if(std::regex_search(action->name, matches, rgx)) {
            if (matches.length() >= 2) {
                Item* item = getItemFromInventory(matches[1]);
                if (item != nullptr) {
                    use(item);
                }

            }
        }
    }
    std::size_t takeAction = action->name.find(Config::instance().GET_ACTION);
    if (takeAction!=std::string::npos) {
        std::regex rgx(Config::instance().GET_REGEX_ACTION);
        std::smatch matches;
        if(std::regex_search(action->name, matches, rgx)) {
            if (matches.length() >= 2) {
                take(matches[1]);
            }
        }
    }

    std::size_t attackAction = action->name.find(Config::instance().ATTACK_ACTION);
    if (attackAction!=std::string::npos) {
        std::regex rgx(Config::instance().ATTACK_REGEX_ACTION);
        std::smatch matches;
        if(std::regex_search(action->name, matches, rgx)) {
            if (matches.length() >= 2) {
                GameEntity* enemy = currentRoom->getEnemyByName(matches[1]);
                attack(enemy);
            }
        }
    }


}

void Player::take(std::string itemName) {
    Item* item = Item::findByName(itemName, currentRoom->getItems());
    if (item != nullptr) {
        renderSystem->RenderText("Taking: " + item->name, "green");
        inventory.push_back(item);
        currentRoom->removeItem(item);
        Engine::GameEngineAnalytics::saveAction("Take", std::to_string(takeCounter += 1));

    } else {
        renderSystem->RenderText("There is no " + itemName + " in this place", "yellow");
    }

}

void Player::use(Item *item) {
    renderSystem->RenderText("Using " + item->name, "blue");
    item->use();
}



Item *Player::getItemFromInventory(std::string itemName) {
    std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
    for(int i =0; inventory.size(); i++) {
        Item* item = inventory[i];
        if (item->name == itemName) {
            return item;
        }
    }
    renderSystem->RenderText(Config::instance().NOT_ITEM_FOUND_IN_THE_INVENTORY, "red");
    return nullptr;
}

void Player::attack(GameEntity *gameEntity) {
    if (gameEntity != nullptr ) {
        if (gameEntity->isAlive()) {
            if (inventory.size() > 0) {
                Item* item = inventory[0];
                gameEntity->takeDamage(item->damage);
            } else {
                gameEntity->takeDamage(10);
            }
        } else {
            renderSystem->RenderText(Config::instance().THE_ENEMY_IS_DEATH, "cyan");
        }
        Engine::GameEngineAnalytics::saveAction("Attack", std::to_string(attackCounter += 1));
    } else {
        renderSystem->RenderText(Config::instance().NO_ENEMY_FOUND_IN_THIS_ROOM, "yellow");
    }


}

bool Player::move(std::string direction) {
    std::vector<Door*> doors = currentRoom->getDoors();
    direction[0] = toupper(direction[0]);
    for(int i=0; i < doors.size(); i++) {
        Door* door = doors[i];
        if (door->direction == direction) {
            Room* room = Room::findById(door->to);
            currentRoom = room;
            room->display();
            Engine::GameEngineAnalytics::saveAction("Move", std::to_string(moveCounter += 1));
            return true;
        }
    }
    renderSystem->RenderText(Config::instance().NO_DOORS_FOUND_IN_THAT_DIRECTION, "red");
    return false;
}

void Player::display() {

}

void Player::setRoom(Room *room) {
    room->display();
    currentRoom = room;
}

void Player::setFloor(Floor *floor) {
    floor->display();
}

void Player::info() {
    currentRoom->display();
    renderSystem->RenderText("Player: " + name, "white");
    std::string message = "Health: " + std::to_string(health);
    if (health > 60) {
        renderSystem->RenderText(message, "green");
    } else if( health < 40) {
        renderSystem->RenderText(message, "yellow");
    } else if (health  < 20) {
        renderSystem->RenderText(message, "red");
    }
    if (inventory.size() > 0) {
        std::for_each(inventory.begin(), inventory.end(), [](Item* item) {
           item->display();
        });
    }
}

std::vector<Item *> Player::getItems() {
    if (inventory.size() > 0) {
        return inventory;
    }
    return std::vector<Item *>();
}

