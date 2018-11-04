//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_GAME_H
#define TEXTADVENTURE_GAME_H

#include <iostream>
#include <map>
#include <vector>
#include "../Engine/TextEngine.h"
#include "Room.h"
#include "Floor.h"
#include "Player.h"
#include "Enemy.h"
#include "ActionManager.h"

class Game: public Engine::TextEngine {
public:
    std::string name = "New Game";
    Game();
    ~Game();
    void initialize() override;
    void gameLoop() override;
    void enemiesLoop();

private:
    Player* currentPlayer;
    ActionManager* actionManager;
};


#endif //TEXTADVENTURE_GAME_H
