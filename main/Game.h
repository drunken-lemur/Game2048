//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_GAME_H
#define GAME2048_GAME_H

namespace game2048 {
    namespace main {
        class Game {
        public:
            static int score; // Сумма всех чисел на поле
            static bool endOfGame; // Флаг для завершения основного цикла программы
            static bool isThere2048; // Хранит информацию о том, удалось ли игроку создать плитку 2048 (флаг победы)

            static void start();

            static void initFields();

            static void printGameResult();

        private:
            Game();
        };
    }
}

#endif //GAME2048_GAME_H
