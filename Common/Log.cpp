//
// Created by Gustavo Sanchez on 10/30/18.
//

#include "Log.h"

void Log::Message(std::string msg) {
    std::cout << "Log: " << msg << std::endl;
}

void Log::Error(std::string msg) {
    std::cout << "Error : " << msg << std::endl;
}
