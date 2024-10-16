#include <iostream>
#include <vector>
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "WIRE.h"
#include "Alocar.h"
#include <SFML/Graphics.hpp>

#define INIT_PROTO_X 225
#define INIT_PROTO_Y 150
#define SIZE_PROTOBOARD 400

using namespace std;
using namespace sf;

void plotProtoboard(RenderWindow &window) {
    vector<CircleShape> conector;
    vector<CircleShape>::iterator it;

    int posixy[8][8][2];
    int x, y;

    RectangleShape protoboardBorda(Vector2f(400.f, 400.f));

    protoboardBorda.setOutlineColor(Color::Black);
    protoboardBorda.setOutlineThickness(5.f);
    protoboardBorda.setPosition(205, 135);


    // plot protoboard
    x = INIT_PROTO_X; // as linhas começam no 225
    for (int i = 0; i < 8; i++)
    {
        y = INIT_PROTO_Y; // as colunas começam no 150
        for (int j = 0; j < 8; j++)
        {
            posixy[i][j][0] = x;
            posixy[i][j][1] = y;

            CircleShape shape(5.f);
            shape.setFillColor(sf::Color::Black);
            shape.setPosition(x,y);
            conector.push_back(shape);

            y += 50;
        }
        x += 50;
    }

    //window.draw(protoboardBorda);
    for (it = conector.begin(); it < conector.end(); ++it)
    {
        window.draw(*it);
    }
}

void entradaBits(RenderWindow &window) {
    RectangleShape entradaDados(Vector2(SIZE_PROTOBOARD - 100.f, 50.f));
}

int main() {


    RenderWindow window(sf::VideoMode(800, 800), "SFML works!");



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            
            if (event.mouseButton.button == Mouse::Left){
                cout << "botao esquerdo mouse";
            }
        }



        window.clear(Color::White);
        plotProtoboard(window);
        window.display();
    }
    
    // Alocar alocador;

    // // Criação de componentes lógicos
    // AND andGate(0, 0, 1, 0, 2, 0);
    // OR orGate(0, 0, 1, 1, 2, 1);
    // NOT notGate(0, 0, 2, 2);
    // WIRE wire(0, 0, 1, 1);

    // // Adiciona os componentes ao alocador e os aloca
    // alocador.adicionarComponente(&andGate);
    // alocador.adicionarComponente(&orGate);
    // alocador.adicionarComponente(&notGate);
    // alocador.adicionarComponente(&wire);

    // // Executa a simulação
    // alocador.simular();

    // // Exibe o estado da protoboard
    // alocador.imprimirBoard();

    return 0;
}
