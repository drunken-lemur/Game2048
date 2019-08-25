//
// Created by Alexey Karasev on 25/08/2019.
//

#include <string>
#include <sstream>
#include "Sprite.h"
#include "../main/Constants.h"

using namespace std;
using namespace game2048::main;
using namespace game2048::graphics;

Sprite *Sprite::Cell0 = new Sprite(0);
Sprite *Sprite::Cell2 = new Sprite(2);
Sprite *Sprite::Cell4 = new Sprite(4);
Sprite *Sprite::Cell8 = new Sprite(8);
Sprite *Sprite::Cell16 = new Sprite(16);
Sprite *Sprite::Cell32 = new Sprite(32);
Sprite *Sprite::Cell64 = new Sprite(64);
Sprite *Sprite::Cell128 = new Sprite(128);
Sprite *Sprite::Cell256 = new Sprite(256);
Sprite *Sprite::Cell512 = new Sprite(512);
Sprite *Sprite::Cell1024 = new Sprite(1024);
Sprite *Sprite::Cell2048 = new Sprite(2048);

Sprite::Sprite(int number) {
    stringstream name;
    spriteNumber = number;
    name << "res/" << number << ".png";

    texture = new sf::Texture();
    texture->loadFromFile(name.str(), sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));

    sprite = new sf::Sprite(*texture);
}

Sprite::~Sprite() {
    delete sprite;
    delete texture;
}

sf::Texture *Sprite::getTexture() {
    return texture;
}

int Sprite::getSpriteNumber() {
    return spriteNumber;
}

sf::Sprite *Sprite::getSprite() {
    return sprite;
}

Sprite *Sprite::getSprite(int number) {
    switch (number) {
        case 2:
            return Cell2;
        case 4:
            return Cell4;
        case 8:
            return Cell8;
        case 16:
            return Cell16;
        case 32:
            return Cell32;
        case 64:
            return Cell64;
        case 128:
            return Cell128;
        case 256:
            return Cell256;
        case 512:
            return Cell512;
        case 1024:
            return Cell1024;
        case 2048:
            return Cell2048;
        default:
            return Cell0;
    }
    return nullptr;
}
