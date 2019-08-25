cmake_minimum_required(VERSION 3.14)
project(Game2048)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game2048 main.cpp main/Game.cpp main/Game.h keyboard/KeyboardHandleModule.cpp keyboard/KeyboardHandleModule.h graphics/GraphicsModule.cpp graphics/GraphicsModule.h main/GameField.cpp main/GameField.h main/Direction.h main/Constants.h graphics/Sprite.cpp graphics/Sprite.h res/0.png res/2.png res/4.png res/8.png res/32.png res/64.png res/128.png res/256.png res/512.png res/1024.png res/2048.png)

target_link_libraries(Game2048 sfml-graphics sfml-audio)
