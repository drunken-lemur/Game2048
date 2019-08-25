//
// Created by Alexey Karasev on 24/08/2019.
//

#include <SFML/Graphics.hpp>
#include "KeyboardHandleModule.h"

using namespace sf;
using namespace std;
using namespace game2048::keyboard;

KeyboardHandleModule::KeyboardHandleModule() = default;

/**
 * Считывание последних данных из стека событий, если можулю это необходимо
 */
void KeyboardHandleModule::update() {
    resetValues();

    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        isWasEscPressed = true;
    } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        lastDirectionKey = UP;
    } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        lastDirectionKey = DOWN;
    } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        lastDirectionKey = LEFT;
    } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        lastDirectionKey = RIGHT;
    }
}

/**
 * @return Возвращает направление последней нажатой "стрелочки",
 * либо AWAITING, если не было нажато ни одной
 */
Direction KeyboardHandleModule::lastDirectionKeyPressed() {
    return lastDirectionKey;
}

/**
 * @return Возвращает информацию о том, был ли нажат ESCAPE за последнюю итерацию
 */
bool KeyboardHandleModule::wasEscPressed() {
    return isWasEscPressed;
}

/**
 * Обнуление данных, полученых в при предыдущих запросах
 */
void KeyboardHandleModule::resetValues() {
    isWasEscPressed = false;
    lastDirectionKey = AWAITING;
}
