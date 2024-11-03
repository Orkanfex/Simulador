//
// Created by madeira on 03/11/24.
//

#ifndef BUTTONCOMPONENTAPP_H
#define BUTTONCOMPONENTAPP_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BUttonComponentApp {
    RectangleShape shape;
    Text label;
    bool isSelect;
public:
    BUttonComponentApp(Vector2f position, Font &font, const string &nome);
    void draw(RenderWindow &window);

};



#endif //BUTTONCOMPONENTAPP_H
