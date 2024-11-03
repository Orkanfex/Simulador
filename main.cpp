//#include "Gerenciador_Componentes.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "AppSimulador.h"

#define INIT_PROTO_X 225
#define INIT_PROTO_Y 150
#define SIZE_PROTOBOARD 400
#define PADDING_CONCTOR 50

using namespace std;
using namespace sf;

class Component {
public:
    RectangleShape shape;
    Text label;
    bool isDragging;

    Component(Vector2f size, Vector2f position, const string& text, Font& font)
        : isDragging(false) {
        shape.setSize(size);
        shape.setFillColor(Color::Blue);
        shape.setPosition(position);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(14);
        label.setFillColor(Color::White);
        label.setPosition(position.x + 5, position.y + 5);
    }

    void draw(RenderWindow& window) {
        window.draw(shape);
        window.draw(label);
    }

    // Operador == para comparar componentes
    bool operator==(const Component& other) const {
        // Comparar posição e texto do rótulo
        return shape.getPosition() == other.shape.getPosition() &&
               label.getString() == other.label.getString();
    }
};

struct Connection {
    Vector2f start;
    Vector2f end;
};

void plotProtoboard(RenderWindow &window, vector<CircleShape>& conector) {
    int posixy[8][8][2];
    int x, y;

    RectangleShape protoboardBorda(Vector2f(400.f, 400.f));
    protoboardBorda.setOutlineColor(Color::Black);
    protoboardBorda.setOutlineThickness(5.f);
    protoboardBorda.setPosition(205, 135);

    x = INIT_PROTO_X;
    for (int i = 0; i < 8; i++) {
        y = INIT_PROTO_Y;
        for (int j = 0; j < 8; j++) {
            posixy[i][j][0] = x;
            posixy[i][j][1] = y;

            CircleShape shape(5.f);
            shape.setFillColor(Color::Black);
            shape.setPosition(x, y);
            conector.push_back(shape);

            y += PADDING_CONCTOR;
        }
        x += PADDING_CONCTOR;
    }

    window.draw(protoboardBorda);
    for (auto &shape : conector) {
        window.draw(shape);
    }
}

void drawConnections(RenderWindow &window, const vector<Connection>& connections) {
    for (const auto& conn : connections) {
        Vertex line[] = {
            Vertex(conn.start, Color::Red),
            Vertex(conn.end, Color::Red)
        };
        window.draw(line, 3, Lines);
    }
}

void configureButtonsInput(vector<RectangleShape> &botoes, Font fonte) {
    for (int i = 0; i < 8; i++) {
        RectangleShape botao(Vector2f(20.f, 20.f));
        botoes.push_back(botao);

    }

}
int main() {
    AppSimulador app;
    WireApp wire;
    PortaAndApp pAnd;

    app.registraComponente(&wire);
    app.registraComponente(&pAnd);
    app.mainDoApp();
    //
    // vector<CircleShape> conector;
    // Font font;
    //
    // vector<Component> components;
    // vector<Component> userComponents;
    //
    // components.emplace_back(Vector2f(50.f, 30.f), Vector2f(30, 100), "AND", font);
    // components.emplace_back(Vector2f(50.f, 30.f), Vector2f(30, 150), "OR", font);
    // components.emplace_back(Vector2f(50.f, 30.f), Vector2f(30, 200), "NOT", font);
    //
    // RectangleShape trashCan(Vector2f(60.f, 60.f));
    // trashCan.setFillColor(Color(128, 128, 128));
    // trashCan.setPosition(700, 700);
    //
    // while (window.isOpen()) {
    //     Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == Event::Closed)
    //             window.close();
    //
    //         if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
    //             Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
    //
    //             /*if (firstClick.x != -1) {
    //                 connections.push_back({firstClick, mousePos});
    //                 firstClick = {-1, -1}; // Reseta o primeiro clique
    //             } else {
    //                 firstClick = mousePos; // Armazena o primeiro clique
    //             }*/
    //
    //             // for (int i = 0; i < conector.size(); ++i) {
    //             //     if (conector[i].getGlobalBounds().contains(mousePos)) {
    //             //         if (firstClick.x == -1) {
    //             //             firstClick = conector[i].getPosition();
    //             //         } else {
    //             //             connections.push_back({firstClick, conector[i].getPosition()});
    //             //             firstClick = {-1, -1};
    //             //         }
    //             //     }
    //             // }
    //
    //             for (auto& component : components) {
    //                 if (component.shape.getGlobalBounds().contains(mousePos)) {
    //                     userComponents.emplace_back(component.shape.getSize(),
    //                                                 Vector2f(mousePos.x, mousePos.y),
    //                                                 component.label.getString(), font);
    //                     userComponents.back().isDragging = true;
    //                 }
    //             }
    //
    //             for (auto& component : userComponents) {
    //                 if (component.shape.getGlobalBounds().contains(mousePos)) {
    //                     component.isDragging = true;
    //                 }
    //             }
    //         }
    //
    //         if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
    //             Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
    //             for (auto& component : userComponents) {
    //                 if (component.isDragging) {
    //                     component.isDragging = false;
    //                     if (trashCan.getGlobalBounds().contains(mousePos)) {
    //                         cout << "Componente descartado!" << endl;
    //                         userComponents.erase(remove(userComponents.begin(), userComponents.end(), component), userComponents.end());
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //
    //         if (event.type == Event::MouseMoved) {
    //             Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
    //             for (auto& component : userComponents) {
    //                 if (component.isDragging) {
    //                     component.shape.setPosition(mousePos);
    //                     component.label.setPosition(mousePos.x + 5, mousePos.y + 5);
    //                 }
    //             }
    //         }
    //     }
    //
    //     window.clear(Color::White);
    //
    //     plotProtoboard(window, conector);
    //     plotEntradaBits(window, entradas, botoes, font);
    //     plotSaidaBits(window, saidas, font);  // Plot the output bits
    //     drawConnections(window, connections);
    //
    //     for (auto& component : components) {
    //         component.draw(window);
    //     }
    //     for (auto& component : userComponents) {
    //         component.draw(window);
    //     }
    //
    //     window.draw(trashCan);
    //     drawConnections(window, connections);
    //     window.display();
    // }

    return 0;
}