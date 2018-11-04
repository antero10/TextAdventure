//
// Created by Gustavo Sanchez on 10/26/18.
//

#ifndef TEXTADVENTURE_GAMEENGINE_H
#define TEXTADVENTURE_GAMEENGINE_H


#include "RenderSystem.h"
#include "InputManager.h"
#include "Engine.h"
#include "../Common/Log.h"
#include "../External/tinyxml2.h"
namespace  Engine {
    class TextEngine: public Engine::Engine {
    private:
        Log log;
    protected:
        tinyxml2::XMLDocument doc;
        virtual void initialize() = 0;
        virtual void gameLoop() = 0;
        void renderText(std::string msg, const char* color);
    public:
        TextEngine();
        ~TextEngine();
        void load();
    };


}

#endif //TEXTADVENTURE_GAMEENGINE_H
