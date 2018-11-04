//
// Created by Gustavo Sanchez on 11/2/18.
//
#include "Config.h"
#include "Enemy.h"
#include "Zombie.h"
#include "../Engine/FileSystem.h"
#include "../Engine/GameEngineAnalytics.h"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::load(tinyxml2::XMLElement *element) {
    Component::load(element);
    if (element != nullptr) {
        tinyxml2::XMLElement* healthElement = element->FirstChildElement("Health");
        tinyxml2::XMLElement* damageElement = element->FirstChildElement("Damage");

        if (healthElement != nullptr) {
            health = std::stoi(healthElement->GetText());
        }
        if (damageElement != nullptr) {
            damage = std::stoi(damageElement->GetText());
        }

    }
}

Enemy *Enemy::getEnemyByElement(tinyxml2::XMLElement *element) {
    if (element != nullptr) {
        std::string type = element->FirstChildElement("Type")->GetText();
        if (type == "Zombie") {
            Enemy* zombie = new Zombie();
            zombie->load(element);
            return zombie;
        }
    }
    return nullptr;
}

void Enemy::execute(Action *action) {

}

void Enemy::attack(GameEntity *gameEntity) {
    renderSystem->RenderText(description + " Attacks you", "red");
    gameEntity->setHealth(gameEntity->getHealth() - damage);
    Engine::GameEngineAnalytics::saveAction("ZombieAttack", std::to_string(enemyAttackCounter += 1));
}

void Enemy::display() {
    renderSystem->RenderText(Config::instance().OMG_A_ZOMBIE, "red");
}
