#include <iostream>
#include "Game/Game.h"
int main() {
    Game* game = new Game();
    game->initialize();
    game->gameLoop();
    return 0;
}