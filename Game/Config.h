//
// Created by Gustavo Sanchez on 10/30/18.
//

#ifndef TEXTADVENTURE_CONFIG_H
#define TEXTADVENTURE_CONFIG_H

#include <iostream>

class Config {
public:
    static Config& instance()
    {
        static Config Instance;
        return Instance;
    }
    const char* GAME_SETTINGS_FILE = "../assets/prueba3.xml";
    const char* GAME_ANALYTICS_FILE = "../assets/Analytics.xml";
    const char* GLOBAL_SETTINGS_FILE = "assets/Settings.xml";
    std::string ACTION_NOT_FOUND = "I don't recognize this action";
    std::string ROOM_NOT_FOUND = "No room on that direction";
    std::string NOT_ITEM_FOUND_IN_THE_INVENTORY = "No item found in inventory";
    std::string NORTH = "north";
    std::string WEST = "west";
    std::string SOUTH = "south";
    std::string EAST = "east";
    std::string MOVE_REGEX = "(move|go)";
    std::string TAKE_REGEX = "(take|get|pick)";
    std::string USE_REGEX = "(use)";
    std::string ATTACK_REGEX = "(attack)";
    std::string INFO_REGEX = "(info)";
    std::string ENEMIES_REGEX = "([A-z]+)";
    std::string NORTH_REGEX = "(up|north)";
    std::string EAST_REGEX = "(left|east)";
    std::string SOUTH_REGEX = "(down|south)";
    std::string WEST_REGEX = "(right|west)";
    std::string ITEM_REGEX = "(pistol|gun|recorder|key|revolver)";
    std::string USE_REGEX_ACTION = "use([A-z]+)";
    std::string GET_REGEX_ACTION = "get([A-z]+)";
    std::string ATTACK_REGEX_ACTION = "attack([A-z]+)";
    std::string MOVE_NORTH_ACTION = "moveNorth";
    std::string MOVE_WEST_ACTION = "moveWest";
    std::string MOVE_SOUTH_ACTION = "moveSouth";
    std::string MOVE_EAST_ACTION = "moveEast";
    std::string INFO_ACTION = "infoInfo";
    std::string USE_ACTION = "use";
    std::string GET_ACTION = "get";
    std::string ATTACK_ACTION = "attack";
    std::string EMPTY_ROOM = "This room is empty";
    std::string ENEMY = "Enemy";
    std::string NO_ENEMY_FOUND_IN_THIS_ROOM = "No enemies with that name in this room";
    std::string NO_DOORS_FOUND_IN_THAT_DIRECTION = "No doors found in that direction";
    std::string THE_ENEMY_IS_DEATH = "The enemy is death";
    std::string OMG_A_ZOMBIE = "OMG a zombie!";
    std::string EXIT_ACTION = "(exit|out)";
    std::string YOU_WIN = "You win";
    std::string YOU_LOSE = "You lose";

};




#endif //TEXTADVENTURE_CONFIG_H
