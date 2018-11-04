//
// Created by Gustavo Sanchez on 11/1/18.
//

#include "Engine.h"

Engine::Engine::Engine() {
    inputManager = new InputManager();
    renderSystem = new RenderSystem();
}

Engine::Engine::~Engine() {
    delete inputManager;
    delete renderSystem;

}
