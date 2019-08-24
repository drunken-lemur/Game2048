//
// Created by Alexey Karasev on 24/08/2019.
//
#include <iostream>
#include "Game.h"

using namespace std;
using namespace game2048::main;

int Game::score = 0;
bool Game::endOfGame = false;
bool Game::isThere2048 = false;

Game::Game() = default;

/**
 * Точка входа. Содержит все необходимые действия для одного игрового цикла.
 */
void Game::start() {
    cout << "Game::start" << endl;
    initFields();
    printGameResult();
}

/**
 * Задаёт значения полей для начала игры
 */
void Game::initFields() {
    score = 0;
    endOfGame = false;
    isThere2048 = false;
}

/**
 * Выводит на экран результат игры пользователя -- победа или поражение, очки.
 */
void Game::printGameResult() {
    cout << "You " << (isThere2048 ? "won :)" : "lost :(") << endl;
    cout << "Your score is " << score << endl;
}