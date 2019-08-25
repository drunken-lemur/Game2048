//
// Created by Alexey Karasev on 24/08/2019.
//

#ifndef GAME2048_GRAPHICSMODULE_H
#define GAME2048_GRAPHICSMODULE_H

#include <SFML/Graphics.hpp>
#include "../main/GameField.h"

namespace game2048 {
    namespace graphics {
        class GraphicsModule {
        public:
            GraphicsModule();

            virtual ~GraphicsModule();

            void draw(GameField *gameField);

            void destroy();

            bool isCloseRequested();

        private:
            sf::RenderWindow *window;
        };
    }
}


#endif //GAME2048_GRAPHICSMODULE_H
