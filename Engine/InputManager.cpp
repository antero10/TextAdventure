//
// Created by Gustavo Sanchez on 10/29/18.
//

#include "InputManager.h"
std::string Engine::InputManager::loadInput(std::string waitingSymbol) {
    std::string input;
    std::cout << waitingSymbol;
    std::getline(std::cin, input);
    if (waitingSymbol != "") {
        input = std::regex_replace(input, std::regex(waitingSymbol), "");
    }
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}
