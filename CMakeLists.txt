cmake_minimum_required(VERSION 3.12)
project(TextAdventure)

set(CMAKE_CXX_STANDARD 14)

add_executable(TextAdventure main.cpp Engine/TextEngine.cpp Engine/TextEngine.h Engine/RenderSystem.cpp Engine/RenderSystem.h Game/Room.cpp Game/Room.h Game/Floor.cpp Game/Floor.h Game/Door.cpp Engine/InputManager.cpp Engine/InputManager.h Game/Item.cpp Game/Item.h Common/Log.cpp Common/Log.h Game/Game.h Game/Game.cpp Game/Game.h Engine/FileSystem.cpp Engine/FileSystem.h Game/Config.h Game/Door.h External/tinyxml2.h External/tinyxml2.cpp Game/Player.cpp Game/Player.h Game/ActionManager.cpp Game/ActionManager.h Game/Action.cpp Game/Action.h Engine/Engine.cpp Engine/Engine.h Game/Gun.cpp Game/Gun.h Game/Enemy.cpp Game/Enemy.h Game/Zombie.cpp Game/Zombie.h Game/GameEntity.cpp Game/GameEntity.h Game/Component.cpp Game/Component.h Engine/GameEngineAnalytics.cpp Engine/GameEngineAnalytics.h)