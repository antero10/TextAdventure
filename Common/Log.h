//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_LOG_H
#define TEXTADVENTURE_LOG_H

#include <any>
#include <iostream>

class Log {
public:
    static void Message(std::string msg);
    static void Error(std::string msg);
};


#endif //TEXTADVENTURE_LOG_H
