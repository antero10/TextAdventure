//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_FILESYSTEM_H
#define TEXTADVENTURE_FILESYSTEM_H

#include <iostream>
#include "../External/tinyxml2.h"

namespace Engine {
    class FileSystem {
    public:
        static FileSystem& instance()
        {
            static FileSystem Instance;
            return Instance;
        }
        void loadXML(const char* fileName);
        void createXML(const char* fileName);
        tinyxml2::XMLElement* createElement(const char* name);
        void createElementChild(tinyxml2::XMLElement* element, const char* name, std::string value);
        tinyxml2::XMLDocument doc;
        tinyxml2::XMLDocument analytics;
    private:
        FileSystem();
        ~FileSystem();
    };

}


#endif //TEXTADVENTURE_FILESYSTEM_H
