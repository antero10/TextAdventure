//
// Created by Gustavo Sanchez on 10/31/18.
//
#include <regex>
#include <string>

#include "ActionManager.h"
#include "Config.h"

ActionManager::ActionManager() {

}

ActionManager::~ActionManager() {

}

Action *ActionManager::getAction(std::string action) {
    std::regex ws_re("\\s+");
    std::vector<std::string> actionLine{
            std::sregex_token_iterator(action.begin(), action.end(), ws_re, -1), {}
    }; // split
    std::string verb = "";
    std::string noun = "";
    if (actionLine.size() == 1) {
        if (std::regex_match(actionLine[0], std::regex(Config::instance().ATTACK_REGEX))) {
            verb = "attack";
            noun = "enemy";
        }
        if (std::regex_match(actionLine[0], std::regex(Config::instance().INFO_REGEX))) {
            verb = "info";
            noun = "info";
        }
    }
    else if (actionLine.size() == 2) {
        /*
         * Verbs check
         */
        if (std::regex_match(actionLine[0], std::regex(Config::instance().MOVE_REGEX))) {
            verb = "move";
        }
        else if (std::regex_match(actionLine[0], std::regex(Config::instance().TAKE_REGEX))) {
            verb = "get";
            if (std::regex_match(actionLine[1], std::regex(Config::instance().ITEM_REGEX))) {
                noun = actionLine[1] ;
            }
        }
        else if (std::regex_match(actionLine[0], std::regex(Config::instance().USE_REGEX))) {
            verb = "use";
            if (std::regex_match(actionLine[1], std::regex(Config::instance().ITEM_REGEX))) {
                noun = actionLine[1] ;
            }
        }
        else if (std::regex_match(actionLine[0], std::regex(Config::instance().ATTACK_REGEX))) {
            verb = "attack";
            if (std::regex_match(actionLine[1], std::regex(Config::instance().ENEMIES_REGEX))) {
                noun = actionLine[1];
            }
        }
        /*
         * Noun Check
         */
        if (std::regex_match(actionLine[1], std::regex(Config::instance().NORTH_REGEX))) {
            noun = "north";
        }
        else if (std::regex_match(actionLine[1], std::regex(Config::instance().EAST_REGEX))) {
            noun = "east";
        }
        else if (std::regex_match(actionLine[1], std::regex(Config::instance().SOUTH_REGEX))) {
            noun = "south";
        }
        else if (std::regex_match(actionLine[1], std::regex(Config::instance().WEST_REGEX))) {
            noun = "west";
        }


    } else if (actionLine.size() == 3) {

        /*
         * Attacks like "attack zombie with gun"
         */


    }

    if (verb != "" && noun != "") {
        std::string finalAction = "";
        noun[0] = std::toupper(noun[0]);
        finalAction = verb + noun;
        remove_if(finalAction.begin(), finalAction.end(), isspace);
        return new Action(finalAction);
    }


    return nullptr;
}

std::string ActionManager::loadInput(std::string waitingSymbol ) {
    std::string input;
    std::cout << waitingSymbol;
    std::getline(std::cin, input);
    if (waitingSymbol != "") {
        input = std::regex_replace(input, std::regex(waitingSymbol), "");
    }
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

