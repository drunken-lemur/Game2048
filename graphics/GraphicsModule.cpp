//
// Created by Alexey Karasev on 24/08/2019.
//

#include <sstream>
#include <iostream>
#include "Sprite.h"
#include "GraphicsModule.h"
#include "../main/Constants.h"

using namespace sf;
using namespace std;
using namespace game2048::graphics;

GraphicsModule::GraphicsModule() {
    window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_NAME);
}

GraphicsModule::~GraphicsModule() {
    delete window;
}

void GraphicsModule::draw(GameField *gameField) {
    RectangleShape shape(Vector2f(CELL_SIZE, CELL_SIZE));
    shape.setFillColor(Color::Magenta);
    shape.setPosition(CELL_SIZE, CELL_SIZE);

    window->clear();

//    gameField->setState(0, 0, 2);
//    gameField->setState(1, 1, 4);
//    gameField->setState(2, 2, 8);
//    gameField->setState(3, 3, 16);

    for (int x = 0; x < COUNT_CELLS_X; x++) {
        for (int y = 0; y < COUNT_CELLS_Y; y++) {
            int state = gameField->getState(x, y);
            if (!state) {
                continue;
            }

            sf::Sprite *sprite = Sprite::getSprite(state)->getSprite();
            sprite->setPosition(CELL_SIZE * x, CELL_SIZE * y);
            window->draw(*sprite);
        }
    }

    window->display();
}

void GraphicsModule::destroy() {
    window->close();
}

bool GraphicsModule::isCloseRequested() {
    Event event{};

    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            return true;
        }
    }

    return false;
}

void GraphicsModule::updateScoreInTitle(int score) {
    stringstream title;

    title << SCREEN_NAME << ": " << score;

    window->setTitle(title.str());
}
