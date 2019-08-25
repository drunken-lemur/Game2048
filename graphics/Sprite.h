//
// Created by Alexey Karasev on 25/08/2019.
//

#ifndef GAME2048_SPRITE_H
#define GAME2048_SPRITE_H


#include <SFML/Graphics.hpp>

namespace game2048 {
    namespace graphics {
        class Sprite {
        private:
            int spriteNumber;
            sf::Sprite* sprite;
            sf::Texture* texture;

        public:
            static Sprite* Cell0;
            static Sprite* Cell2;
            static Sprite* Cell4;
            static Sprite* Cell8;
            static Sprite* Cell16;
            static Sprite* Cell32;
            static Sprite* Cell64;
            static Sprite* Cell128;
            static Sprite* Cell256;
            static Sprite* Cell512;
            static Sprite* Cell1024;
            static Sprite* Cell2048;

            explicit Sprite(int number);

            virtual ~Sprite();

            static Sprite* getSprite(int number);

            int getSpriteNumber();

            sf::Texture *getTexture();

            sf::Sprite *getSprite();
        };
    }
}


#endif //GAME2048_SPRITE_H
