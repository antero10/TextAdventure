//
// Created by Gustavo Sanchez on 10/26/18.
//

#include "RenderSystem.h"
#include <map>

Engine::RenderSystem::RenderSystem() {
    colors.insert(std::pair<const char*,const char*>("black", "\033[0;90m"));
    colors.insert(std::pair<const char*,const char*>("red", "\033[0;91m"));
    colors.insert(std::pair<const char*,const char*>("green", "\033[0;92m"));
    colors.insert(std::pair<const char*,const char*>("yellow", "\033[0;93m"));
    colors.insert(std::pair<const char*,const char*>("blue", "\033[0;94m"));
    colors.insert(std::pair<const char*,const char*>("purple", "\033[0;95m"));
    colors.insert(std::pair<const char*,const char*>("cyan", "\033[0;96m"));
    colors.insert(std::pair<const char*,const char*>("white", "\033[0;37m"));


}
Engine::RenderSystem::~RenderSystem() {

}
void Engine::RenderSystem::RenderText(std::string msg, const char* color) {
   const char* colorValue = colors.find(color)->second;
   const char* white = colors.find("white")->second;
   std::cout << colorValue << msg << white << std::endl;
}
