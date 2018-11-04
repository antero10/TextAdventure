//
// Created by Gustavo Sanchez on 11/2/18.
//

#ifndef TEXTADVENTURE_GAMEENGINEANALYTICS_H
#define TEXTADVENTURE_GAMEENGINEANALYTICS_H

#include <iostream>
#include "FileSystem.h"

namespace Engine {
    class GameEngineAnalytics {
    public:
        GameEngineAnalytics();
        ~GameEngineAnalytics();
        static void saveAction(std::string action, std::string value);
    };

}


#endif //TEXTADVENTURE_GAMEENGINEANALYTICS_H
