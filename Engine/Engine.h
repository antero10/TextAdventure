//
// Created by Gustavo Sanchez on 11/1/18.
//

#ifndef TEXTADVENTURE_ENGINE_H
#define TEXTADVENTURE_ENGINE_H

#include "InputManager.h"
#include "RenderSystem.h"
#include "FileSystem.h"

namespace  Engine {
    class Engine {
    public:
        virtual void initialize() = 0;
        virtual void gameLoop() = 0;
        Engine();
        ~Engine();

    protected:
        InputManager* inputManager;
        RenderSystem* renderSystem;
        FileSystem* fileSystem;
    };
}



#endif //TEXTADVENTURE_ENGINE_H
