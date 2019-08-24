#include <iostream>
#include "main/Game.h"

using namespace game2048::main;

int main() {
    setlocale(LC_ALL, "ru");
    Game::start();

    std::cout << std::endl << "Ok." << std::endl;
    return 0;
}