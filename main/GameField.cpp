//
// Created by Alexey Karasev on 24/08/2019.
//

#include "GameField.h"

using namespace game2048::main;

GameField::GameField() {
    for (int x = 0; x < COUNT_CELLS_X; x++) { // NOLINT(modernize-loop-convert)
        for (int y = 0; y < COUNT_CELLS_Y; y++) {
//            theField[x][y] = 0;
            setState(x, y, 0);
        }
    }
}

/**
 * Возвращает состояние ячейки поля по координатам
 *
 * @param x Координата ячейки X
 * @param y Координата ячейки Y
 * @return Состояние выбранной ячейки
 */
int GameField::getState(int x, int y) {
    return theField[x][y];
}

/**
 * Изменяет состояние ячейки поля по координатам
 *
 * @param x Координата ячейки X
 * @param y Координата ячейки Y
 * @param state Новое состояние для этой ячейки
 */
void GameField::setState(int x, int y, int state) {
    // TODO check input maybe?

    theField[x][y] = state;
}

/**
 * Возвращает массив состояний ячеек столбца под номером i
 *
 * @param i Номер запрашиваемого столбца
 * @return Массив состояний ячеек столбца
 */
array<int, COUNT_CELLS_Y> GameField::getColumn(int x) {
    return theField[x];
}

/**
 * Изменяет столбец под номером i
 *
 * @param i Номер изменяемого столбца
 * @param newColumn Массив новых состояний ячеек столбца
 */
void GameField::setColumn(int x, array<int, COUNT_CELLS_Y> newColumn) {
//    theField[x] = newColumn;
    for(int y = 0; y < COUNT_CELLS_Y; y++) {
        theField[x][y] = newColumn[y];
    }
}

array<int, COUNT_CELLS_X> GameField::getLine(int y) {
    return {}; //  todo
}

void GameField::setLine(int y, array<int, COUNT_CELLS_X> newLine) {
    for (int x = 0; x < COUNT_CELLS_X; x++) {
        theField[x][y] = newLine[x];
    }
}
