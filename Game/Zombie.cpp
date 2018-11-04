//
// Created by Gustavo Sanchez on 11/2/18.
//

#include "Zombie.h"

Zombie::Zombie() {
    name = "Zombie";
    health = 50;
}

Zombie::~Zombie() {

}

void Zombie::load(tinyxml2::XMLElement *element) {
    Enemy::load(element);
}

bool Zombie::move(std::string direction) {
    if (direction == "") {
        //TODO

    }
}

void Zombie::execute(Action *action) {

}

void Zombie::attack(GameEntity *gameEntity) {
    Enemy::attack(gameEntity);
}

void Zombie::display() {
    Enemy::display();
}
