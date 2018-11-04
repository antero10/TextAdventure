//
// Created by Gustavo Sanchez on 10/26/18.
//

#ifndef TEXTADVENTURE_RENDERSYSTEM_H
#define TEXTADVENTURE_RENDERSYSTEM_H

#include <iostream>
#include <stdlib.h>
#include <map>

namespace  Engine {
    class RenderSystem {
    private:
        std::string name = "Game";
        int width = 0;
        int heihgt = 0;
        bool fullscreen = false;
        std::map<const char*,const char*> colors;


    public:
        RenderSystem();
        ~RenderSystem();
        void initialize();
        void RenderText(std::string msg, const char* color);
    };
}



#endif //TEXTADVENTURE_RENDERSYSTEM_H
