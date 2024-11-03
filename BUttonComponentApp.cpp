//
// Created by madeira on 03/11/24.
//

#include "BUttonComponentApp.h"

BUttonComponentApp::BUttonComponentApp(Vector2f position, Font &font, const string &nome) {
    shape.setSize(Vector2f(50.f, 30.f));
    shape.setFillColor(Color::Blue);
    shape.setPosition(position.x, position.y);

    label.setFont(font);
    label.setString("nomes");
    label.setCharacterSize(14);
    label.setFillColor(Color::White);
    label.setPosition(position.x + 5, position.y + 5);

    isSelect = 0;
}

void BUttonComponentApp::draw(RenderWindow &window) {
    window.draw(shape);
    window.draw(label);
}
