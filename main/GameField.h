//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_GAMEFIELD_H
#define GAME2048_GAMEFIELD_H

#include <array>
#include "Constants.h"

using namespace std;
using namespace game2048::main;

namespace game2048 {
    namespace main {
        class GameField {
        public:
            GameField();

            int getState(int x, int y);

            void setState(int x, int y, int state);

            array<int, COUNT_CELLS_Y> getColumn(int x);

            void setColumn(int x, array<int, COUNT_CELLS_Y> newColumn);

            array<int, COUNT_CELLS_X> getLine(int y);

            void setLine(int y, array<int, COUNT_CELLS_X> newLine);

            void log();

        private:
            array<array<int, COUNT_CELLS_Y>, COUNT_CELLS_X> theField;
        };
    }
}


#endif //GAME2048_GAMEFIELD_H
