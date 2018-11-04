//
// Created by Gustavo Sanchez on 10/26/18.
//

#include "TextEngine.h"

Engine::TextEngine::TextEngine() {
}

Engine::TextEngine::~TextEngine() {

}

void Engine::TextEngine::load() {
    Log::Message("Loading Game Settings...");
}

void Engine::TextEngine::renderText(std::string msg, const char *color) {
    renderSystem->RenderText(msg, color);
}
