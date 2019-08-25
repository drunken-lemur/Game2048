//
// Created by Alexey Karasev on 24/08/2019.
//
#include <iostream>
#include <cstdlib>
#include "Game.h"

using namespace std;
using namespace game2048::main;
using namespace game2048::graphics;
using namespace game2048::keyboard;

int Game::score = 0;
bool Game::endOfGame = false;
bool Game::isThere2048 = false;
Direction Game::direction = Direction::AWAITING;

GameField *Game::gameField = nullptr;
GraphicsModule *Game::graphicsModule = nullptr;
KeyboardHandleModule *Game::keyboardModule = nullptr;

Game::Game() = default;

/**
 * Точка входа. Содержит все необходимые действия для одного игрового цикла.
 */
void Game::start() {
    initFields();
    createInitialCells();

    while (!endOfGame) {
        input();

        logic();

        graphicsModule->draw(gameField);
    }

    graphicsModule->destroy();

    printGameResult();
}

/**
 * Задаёт значения полей для начала игры
 */
void Game::initFields() {
    score = 0;
    endOfGame = false;
    isThere2048 = false;
    direction = Direction::AWAITING;

    gameField = new GameField();
    graphicsModule = new GraphicsModule();
    keyboardModule = new KeyboardHandleModule();
}

/**
 * Выводит на экран результат игры пользователя -- победа или поражение, очки.
 */
void Game::printGameResult() {
    cout << "You " << (isThere2048 ? "won :)" : "lost :(") << endl;
    cout << "Your score is " << score << endl;
}

/**
 * Создаёт на поле начальные ячейки
 */
void Game::createInitialCells() {
    for (int i = 0; i < COUNT_INITITAL_CELLS; i++) {
        generateNewCell();
    }
}

/**
 * Создаёт в случайной пустой клетке игрового поля плитку (с ненулевым состоянием).
 */
void Game::generateNewCell() {
    srand(time(NULL));
    bool placed = false;
    int randomX = rand() % COUNT_CELLS_X;
    int randomY = rand() % COUNT_CELLS_Y;
    int currentX = randomX;
    int currentY = randomY;
    int state = ((rand() % 100) <= CHANCE_OF_LUCKY_SPAWN)
                ? LUCKY_INITIAL_CELL_STATE
                : INITIAL_CELL_STATE;

    while (!placed) {
        if (gameField->getState(currentX, currentY) == 0) {
            gameField->setState(currentX, currentY, state);
            placed = true;
        } else {
            if (currentX + 1 < COUNT_CELLS_X) {
                currentX++;
            } else {
                currentX = 0;

                if (currentY + 1 < COUNT_CELLS_Y) {
                    currentY++;
                } else {
                    currentY = 0;
                }
            }

            if ((currentX == randomX) && (currentY == randomY)) {  // No place -> Something went wrong
                // ErrorCatcher.cellCreationFailure();
                throw "No place -> Something went wrong";
            }
        }
    }

    score += state;
}

/**
 * Считывает пользовательский ввод.
 * Изменяет Main.direction и endOfGame;
 */
void Game::input() {
    keyboardModule->update();

    direction = keyboardModule->lastDirectionKeyPressed();

    endOfGame = endOfGame || graphicsModule->isCloseRequested() || keyboardModule->wasEscPressed();
}

/**
 * Основная логика игры.
 *
 * Если пользователь определил направление, вызывает метод сдвига.
 * Если сдвиг удался, создаёт новую плитку.
 */
void Game::logic() {
    if (direction != Direction::AWAITING) {
        if (shift(direction)) {
            generateNewCell();
        }

        direction = Direction::AWAITING;
    }
}

/**
 * Изменяет gameField, сдвигая все ячейки в указанном направлении,
 * вызывая shiftRow() для каждой строки/столбца (в зависимости от направления)
 *
 * @param direction Направление, в котором необходимо совершить сдвиг
 * @return Возвращает true, если сдвиг прошёл успешно (поле изменилось)
 */
bool Game::shift(Direction d) {
    bool ret = false;

    switch (d) {
        case UP:
        case DOWN:
            generateNewCell(); // todo
            /* По очереди сдвигаем числа всех столбцов в нужном направлении */
            for (int i = 0; i < COUNT_CELLS_X; i++) {
                /* Запрашиваем очередной столбец */
                /* В зависимости от направления сдвига, меняем или не меняем порядок чисел на противоположный */
                /* Пытаемся сдвинуть числа в этом столбце */
                /* Возвращаем линию в исходный порядок */
                /* Записываем изменённый столбец */
                /* Если хоть одна линия была изменена, значит было изменено всё поле */
            }
            break;

        case LEFT:
        case RIGHT:
            generateNewCell(); // todo
            /* По очереди сдвигаем числа всех строк в нужном направлении */
            for (int i = 0; i < COUNT_CELLS_Y; i++) {
                /* Запрашиваем очередную строку */
                /* В зависимости от направления сдвига, меняем или не меняем порядок чисел на противоположный */
                /* Пытаемся сдвинуть числа в этом столбце */
                /* Возвращаем линию в исходный порядок */
                /* Записываем изменённую строку */
                /* Если хоть одна линия была изменена, значит было изменено всё поле */
            }
            break;

        default:
            throw "ErrorCatcher.shiftFailureWrongParam();";
    }

    return ret;
}
