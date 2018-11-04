//
// Created by Gustavo Sanchez on 10/30/18.
//
#include <algorithm>
#include "Config.h"
#include "Game.h"
#include "../Engine/TextEngine.h"
#include "../External/tinyxml2.h"
#include "../Engine/GameEngineAnalytics.h"

Game::Game() {
    currentPlayer = new Player();
    actionManager = new ActionManager();


}

Game::~Game() {
    delete currentPlayer;
    delete actionManager;
}



void Game::initialize() {
    Log::Message("Initializing the game...");
    fileSystem->instance().loadXML(Config::instance().GAME_SETTINGS_FILE);
    tinyxml2::XMLElement* gameSettings =  fileSystem->instance().doc.FirstChildElement("GameSettings");
    if (gameSettings != nullptr) {
        Room* room = Room::findById(1);
        Floor* floor = Floor::findById(1);
        currentPlayer->setFloor(floor);
        currentPlayer->setRoom(room);
    }

}

void Game::gameLoop() {

    while(currentPlayer->isAlive() || currentPlayer->getItems().size() >= 3) {
        std::string action = actionManager->loadInput(">");
        Action* userAction = actionManager->getAction(action);
        if (userAction != nullptr) {
            enemiesLoop();
            currentPlayer->execute(userAction);
        } else {
            renderText(Config::instance().ACTION_NOT_FOUND, "red");
        }
    };
    if (!currentPlayer->isAlive()) {
        renderSystem->RenderText(Config::instance().YOU_LOSE, "red");
    } else {
        renderSystem->RenderText(Config::instance().YOU_WIN, "green");
    }

}

void Game::enemiesLoop() {
  if (currentPlayer->getCurrentRoom()->getEnemies().size() > 0) {
      std::vector<GameEntity*> enemies = currentPlayer->getCurrentRoom()->getEnemies();
      for (int i = 0; i < enemies.size() >= 1; ++i) {
          enemies[i]->attack(currentPlayer);
      }
  }
}

