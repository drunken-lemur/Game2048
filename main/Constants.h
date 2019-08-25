//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_CONSTANTS_H
#define GAME2048_CONSTANTS_H

#include <string>

namespace game2048 {
    namespace main {
        /* Размер одной плитки */
        const int CELL_SIZE = 128;

        /* Количество ячеек на экране по горизонтали и вертикали */
        const int COUNT_CELLS_X = 4;
        const int COUNT_CELLS_Y = 4;

        /* Параметры окна */
        const std::string SCREEN_NAME = "Game 2048";
        const int SCREEN_WIDTH = COUNT_CELLS_X * CELL_SIZE;
        const int SCREEN_HEIGHT = COUNT_CELLS_Y * CELL_SIZE;

        /* Шанс (в процентах) определяется здесь, что появится плитка со значением не 2, а 4 */
        const int CHANCE_OF_LUCKY_SPAWN = 17;

        /* Состояния новосозданых клеток (при условии срабатывания CHANCE_OF_LUCKY_SPAWN и без него) */
        const int LUCKY_INITIAL_CELL_STATE = 4;
        const int INITIAL_CELL_STATE = 2;

        /* Количество определённых к первому ходу пользователя ячеек */
        const int COUNT_INITITAL_CELLS = 2;
    }
}


#endif //GAME2048_CONSTANTS_H
