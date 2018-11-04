//
// Created by Gustavo Sanchez on 11/2/18.
//

#include "GameEntity.h"
#include <string>

void GameEntity::setHealth(int newHealth) {
    if (newHealth < health) {
        renderSystem->RenderText(name+" has been attacked, now the life is: " + std::to_string(newHealth), "cyan");
    }
    health = newHealth;
}

bool GameEntity::isAlive() {
    if (health > 0) {
        return true;
    }
    return false;
}

void GameEntity::takeDamage(int damage) {
    (health - damage) >= 0 ? setHealth(health - damage) : setHealth(0);
}
