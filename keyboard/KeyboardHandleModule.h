//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_KEYBOARDHANDLEMODULE_H
#define GAME2048_KEYBOARDHANDLEMODULE_H

#include "../main/Direction.h"

using namespace game2048::main;

namespace game2048 {
    namespace keyboard {
        class KeyboardHandleModule {
        public:
            KeyboardHandleModule();

            void update();

            Direction lastDirectionKeyPressed();

            bool wasEscPressed();

        private:
            bool isWasEscPressed{};
            Direction lastDirectionKey;

            void resetValues();
        };
    }
}


#endif //GAME2048_KEYBOARDHANDLEMODULE_H
