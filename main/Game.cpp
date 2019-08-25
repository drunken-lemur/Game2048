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

        // move to keyboard handler
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) ){
            graphicsModule->destroy();
            start();
            endOfGame = true;
        }
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
    direction = AWAITING;

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
    if (direction != AWAITING) {
        gameField->log();

        if (shift(direction)) {
            generateNewCell();
        }

        direction = AWAITING;
        graphicsModule->updateScoreInTitle(score);
    }
}

/**
 * Изменяет gameField, сдвигая все ячейки в указанном направлении,
 * вызывая shiftRow() для каждой строки/столбца (в зависимости от направления)
 *
 * @param direction Направление, в котором необходимо совершить сдвиг
 * @return Возвращает true, если сдвиг прошёл успешно (поле изменилось)
 */
bool Game::shift(Direction direction) {
    bool ret = false;

    switch (direction) {
        case UP:
        case DOWN:
            /* По очереди сдвигаем числа всех столбцов в нужном направлении */
            for (int i = 0; i < COUNT_CELLS_X; i++) {
                /* Запрашиваем очередной столбец */
                array<int, COUNT_CELLS_Y> arg = gameField->getColumn(i);

                /* В зависимости от направления сдвига, меняем или не меняем порядок чисел на противоположный */
                if (direction == UP) {
                    array<int, COUNT_CELLS_Y> tmp{};

                    for (int e = 0; e < COUNT_CELLS_Y; e++) {
                        tmp[e] = arg[COUNT_CELLS_Y - e - 1];
                    }

                    arg = tmp;
                }

                /* Пытаемся сдвинуть числа в этом столбце */
                ShiftRowResult *result = shiftRow(arg);

                /* Возвращаем линию в исходный порядок */
                if (direction == UP) {
                    array<int, COUNT_CELLS_Y> tmp{};

                    for (int e = 0; e < COUNT_CELLS_Y; e++) {
                        tmp[e] = result->getShiftedRow()[COUNT_CELLS_Y - e - 1];
                    }

                    result->setShiftedRow(tmp);
                }

                /* Записываем изменённый столбец */
                gameField->setColumn(i, result->getShiftedRow());

                /* Если хоть одна линия была изменена, значит было изменено всё поле */
                ret = ret || result->didAnythingMove;

                delete result;
            }
            break;

        case LEFT:
        case RIGHT:
            /* По очереди сдвигаем числа всех строк в нужном направлении */
            for (int i = 0; i < COUNT_CELLS_Y; i++) {
                /* Запрашиваем очередную строку */
                array<int, COUNT_CELLS_X> arg = gameField->getLine(i);

                /* В зависимости от направления сдвига, меняем или не меняем порядок чисел на противоположный */
                if (direction == RIGHT) {
                    array<int, COUNT_CELLS_X> tmp{};

                    for (int e = 0; e < COUNT_CELLS_Y; e++) {
                        tmp[e] = arg[COUNT_CELLS_Y - e - 1];
                    }

                    arg = tmp;
                }

                /* Пытаемся сдвинуть числа в этом строке */
                ShiftRowResult *result = shiftRow(arg);

                /* Возвращаем линию в исходный порядок */
                if (direction == RIGHT) {
                    array<int, COUNT_CELLS_X> tmp{};

                    for (int e = 0; e < COUNT_CELLS_X; e++) {
                        tmp[e] = result->getShiftedRow()[COUNT_CELLS_X - e - 1];
                    }

                    result->setShiftedRow(tmp);
                }

                /* Записываем изменённую строку */
                gameField->setLine(i, result->getShiftedRow());

                /* Если хоть одна линия была изменена, значит было изменено всё поле */
                ret = ret || result->didAnythingMove;

                delete result;
            }
            break;

        default:
            throw "ErrorCatcher.shiftFailureWrongParam();";
    }

    return ret;
}

ShiftRowResult *Game::shiftRow(array<int, COUNT_CELLS_X> oldRow) {
    ShiftRowResult *result = new ShiftRowResult();

    result->setShiftedRow(oldRow);

    array<int, COUNT_CELLS_X> oldRowWithoutZeroes{};
    {
        int q = 0;

        for (int i = 0; i < COUNT_CELLS_X; i++) {
            if (oldRow[i] != 0) {
                if (q != i) {
                    /*
                     * Это значит, что мы передвинули ячейку
                     * на место какого-то нуля (пустой плитки)
                     */
                    result->didAnythingMove = true;
                }

                oldRowWithoutZeroes[q] = oldRow[i];
                q++;
            }
        }

        /* Чтобы избежать null'ов в конце массива */
        for (int i = q; i < COUNT_CELLS_X; i++) {
            oldRowWithoutZeroes[i] = 0;
        }
    }

    result->setShiftedRow({});

    {
        int q = 0;

        int i = 0;

        while (i < COUNT_CELLS_X) {
            if ((i + 1 < COUNT_CELLS_X) && (oldRowWithoutZeroes[i] == oldRowWithoutZeroes[i + 1])
                && oldRowWithoutZeroes[i] != 0) {
                result->didAnythingMove = true;
                result->shiftedRow[q] = oldRowWithoutZeroes[i] * 2;
                if (result->shiftedRow[q] == 2048) {
                    merged2048();
                }
                i++;
            } else {
                result->shiftedRow[q] = oldRowWithoutZeroes[i];
            }

            q++;
            i++;
        }

        // Чтобы избежать null'ов в конце массива
        for (int j = q; j < COUNT_CELLS_X; j++) {
            result->shiftedRow[j] = 0;
        }
    }

    return result;
}

/**
 * Описывает действия в случае победы пользователя (если пользователь создал плитку 2048).
 *
 * Сейчас: устанавливает флаг победы на true, завершает игру.
 */
void Game::merged2048() {
    endOfGame = true;
    isThere2048 = true;
}
