#include <iostream>
#include "main/Game.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace game2048::main;

int main() {
    setlocale(LC_ALL, "ru");
    Game::start();

    cout << endl << "Ok." << endl;
    return 0;

//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen()) {
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//            break;
//        }
//        sf::Event event{};
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
}