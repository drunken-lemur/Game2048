//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_GAME_H
#define GAME2048_GAME_H

#include "../main/Constants.h"
#include "../main/GameField.h"
#include "../main/Direction.h"
#include "../graphics/GraphicsModule.h"
#include "../keyboard/KeyboardHandleModule.h"

using namespace game2048::main;
using namespace game2048::graphics;
using namespace game2048::keyboard;

namespace game2048 {
    namespace main {
        class Game {
        private:
            static int score; // Сумма всех чисел на поле
            static bool endOfGame; // Флаг для завершения основного цикла программы
            static bool isThere2048; // Хранит информацию о том, удалось ли игроку создать плитку 2048 (флаг победы)
            static Direction direction; // Направление, в котором требуется сдвиг клеток поля

            static GameField *gameField;
            static GraphicsModule *graphicsModule;
            static KeyboardHandleModule *keyboardModule;

            Game();

            static void initFields();

            static void printGameResult();

            static void createInitialCells();

            static void generateNewCell();

            static void input();

            static void logic();

            static bool shift(Direction direction);

        public:
            static void start();
        };
    }
}

#endif //GAME2048_GAME_H
