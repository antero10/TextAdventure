//
// Created by Gustavo Sanchez on 10/26/18.
//

#include <algorithm>
#include <string>
#include "Room.h"
#include "Config.h"
#include "Enemy.h"
#include "GameEntity.h"
#include "../Engine/FileSystem.h"
#include "../Engine/RenderSystem.h"
Room::Room() {

}

Room::~Room() {
    std::for_each(doors.begin(), doors.end(),[](Door* door){
       delete door;
    });
}


void Room::load(tinyxml2::XMLElement* element) {

    Component::load(element);

    tinyxml2::XMLElement* doorsElement = element->FirstChildElement("Doors");
    if (doorsElement != nullptr) {
        for(tinyxml2::XMLElement* door = doorsElement->FirstChildElement("Door"); door != NULL; door = door->NextSiblingElement("Door"))
        {
            Door* nDoor = new Door();
            nDoor->load(door);
            doors.push_back(nDoor);
        }
    }

    tinyxml2::XMLElement* enemiesElement =  element->FirstChildElement("Enemies");
    if (enemiesElement != nullptr) {
        for(tinyxml2::XMLElement* enemyElement = enemiesElement->FirstChildElement("Enemy"); enemyElement != NULL; enemyElement = enemiesElement->NextSiblingElement("Enemy")) {
            Enemy* enemy = Enemy::getEnemyByElement(enemyElement);
            if (enemy != nullptr) {
                enemies.push_back(enemy);
            }
        }
    }

    tinyxml2::XMLElement* itemsElement =  element->FirstChildElement("Items");
    if (itemsElement != nullptr) {
        for(tinyxml2::XMLElement* itemElement = itemsElement->FirstChildElement("Item"); itemElement != NULL; itemElement = itemsElement->NextSiblingElement("Item")) {
            Item* item = Item::getItemByElement(itemElement);
            if (item != nullptr) {
                items.push_back(item);
            }
        }
    }

}

Room *Room::findById(int id) {
    Engine::FileSystem::instance().loadXML(Config::instance().GAME_SETTINGS_FILE);
    tinyxml2::XMLElement* gameSettings =  Engine::FileSystem::instance().doc.FirstChildElement("GameSettings");
    tinyxml2::XMLElement* floors =  gameSettings->FirstChildElement("Floors");
    if (gameSettings != nullptr && floors != nullptr) {
        for(tinyxml2::XMLElement* floor = floors->FirstChildElement("Floor"); floor != NULL; floor = floor->NextSiblingElement("Floor"))
        {
            tinyxml2::XMLElement* rooms =  floor->FirstChildElement("Rooms");
            for(tinyxml2::XMLElement* room = rooms->FirstChildElement("Room"); room != NULL; room = room->NextSiblingElement("Room"))
            {
                Room* room1 = new Room();
                room1->load(room);
                if (id == room1->getId()) {
                    return room1;
                }
            }
        }
    }

    return nullptr;
}

void Room::display() {
    Component::display();
    if (enemies.size() > 0) {
        std::for_each(enemies.begin(), enemies.end(), [](GameEntity* enemy){
            enemy->display();
        });

    }
}

GameEntity *Room::getEnemyByName(std::string name) {
    if (enemies.size() > 0) {
        if (name != Config::instance().ENEMY) {
            for (int i = 0; i <= enemies.size() - 1; ++i) {
                GameEntity *enemy = enemies[i];
                if (enemy->name == name) {
                    return enemy;
                }
            }
        } else {
            return enemies[0];
        }
    } else {
        renderSystem->RenderText(Config::instance().EMPTY_ROOM, "yellow");
    }
    return nullptr;
}

GameEntity *Room::getEnemy(GameEntity *gameEntity) {
    for (int i = 0; i < enemies.size() - 1; ++i) {
        GameEntity* enemy = enemies[i];
        if (enemy->name == gameEntity->name) {
            return enemy;
        }
    }
    return nullptr;
}

void Room::removeEnemy(GameEntity *enemy) {
    if (enemies.size() > 0) {
        for (int i = 0; i < enemies.size() - 1; ++i) {
            GameEntity* localEnemy = enemies[i];
            if (localEnemy->id == enemy->id) {
                enemies.erase(enemies.begin() + i);
            }
        }
    }

}

void Room::removeItem(Item *item) {
    if (items.size() > 0) {
        for (int i = 0; i <= items.size() ; ++i) {
            Item* localItem = items[i];
            if (localItem->id == item->id) {
                items.erase(items.begin() + i);
            }
        }
    }

}
