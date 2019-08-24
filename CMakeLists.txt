cmake_minimum_required(VERSION 3.14)
project(Game2048)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game2048 main.cpp main/Game.cpp main/Game.h keyboard/KeyboardHandleModule.cpp keyboard/KeyboardHandleModule.h graphics/GraphicsModule.cpp graphics/GraphicsModule.h)

target_link_libraries(Game2048 sfml-graphics sfml-audio)
