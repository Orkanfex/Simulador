//
// Created by madeira on 02/11/24.
//

#include "AppSimulador.h"
#include <iostream>


AppSimulador::AppSimulador() {

    for (int i = 0; i < 8; i++) {
        input.push_back(0);
        output.push_back(0);
    }
}

void AppSimulador::registraComponente(ComponentesApp * pComponente) {
    registroDeComponentes.push_back(pComponente->alocarComponenteApp());
}

void AppSimulador::mainDoApp() {
    RenderWindow window(VideoMode(800, 800), "Simulador Lógico");
    vector<RectangleShape> botoes;
    vector<Text> bitsEntrada, bitsSaida;
    vector<BUttonComponentApp> painel;
    Font font;

    if (!font.loadFromFile("../Fontes/ARIAL.TTF")) {
        std::cerr << "Erro ao carregar a fonte!" << endl;
    }

    configureButtonsInput(botoes, font, bitsEntrada);
    painelComponentes(window, font, painel);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                for (int i = 0; i < botoes.size(); ++i) {
                    if (botoes[i].getGlobalBounds().contains(mousePos)) {
                        input[i] = !input[i];
                    }
                }
            }
        }

        window.clear(Color::White);

        drawPainel(window, painel);
        plotEntradaBIts(window, botoes, font);
        plotSaidaBits(window, font);

        window.display();
    }
}
void AppSimulador::configureButtonsInput(vector<RectangleShape> &botoes,
    Font fonte, vector<Text> &text) {
    for (int i = 0; i < 8; i++) {
        RectangleShape botao(Vector2f(20.f, 20.f));
        botoes.push_back(botao);

        Text bitText;
        bitText.setFont(fonte);
        bitText.setCharacterSize(20);
        bitText.setFillColor(Color::Black);
        bitText.setString(to_string(input[i]));
    }
}

void AppSimulador::plotEntradaBIts(RenderWindow &window,
    vector<RectangleShape> &botoes, Font font) {

    int x, y;
    RectangleShape entradaDados(Vector2f(SIZE_PROTOBOARD / 1.4f, 30.f));
    vector<Text> bitsTxt;

    y = INIT_PROTO_Y + SIZE_PROTOBOARD + (PADDING_CONCTOR / 2);
    x = INIT_PROTO_X - (PADDING_CONCTOR / 2) + (PADDING_CONCTOR * 1.6);

    entradaDados.setOutlineThickness(5.f);
    entradaDados.setOutlineColor(Color::Black);
    entradaDados.setPosition(x - PADDING_CONCTOR / 2.f, y + (PADDING_CONCTOR / 2.f));

    window.draw(entradaDados);

    vector<RectangleShape>::iterator it;
    int j = 0;
    for (it = botoes.begin(); it < botoes.end(); it++, j++) {
        CircleShape shape(5.f);
        shape.setFillColor(Color::Black);
        shape.setPosition(x, y);
        window.draw(shape);

        it->setFillColor(input[j] == 0 ? Color::Red : Color::Green);
        it->setPosition(x, y + 70);
        window.draw(*it);

        Text bitText;
        bitText.setFont(font);
        bitText.setCharacterSize(20);
        bitText.setFillColor(Color::Black);
        bitText.setPosition(x + (PADDING_CONCTOR / 15), y + 30);
        bitText.setString(to_string(input[j]));
        window.draw(bitText);

        x += (PADDING_CONCTOR / 1.5);
    }

}

void AppSimulador::plotSaidaBits(RenderWindow &window, Font fonte) {
    int x, y;
    RectangleShape saidaDados(Vector2f(SIZE_PROTOBOARD / 1.4f, 30.f));
    vector<Text> bitsTxt;

    // Ajuste o valor de 'y' para que o vetor de saída apareça acima da protoboard
    y = INIT_PROTO_Y - (PADDING_CONCTOR * 2);
    x = INIT_PROTO_X - (PADDING_CONCTOR / 2) + (PADDING_CONCTOR * 1.6);

    saidaDados.setOutlineThickness(5.f);
    saidaDados.setOutlineColor(Color::Black);
    saidaDados.setPosition(x - PADDING_CONCTOR / 2.f, y + (PADDING_CONCTOR / 2.f));

    window.draw(saidaDados);
    // Loop para desenhar os bits de saída
    for (int j = 0; j < 8; j++) {

        Text bitText;
        bitText.setFont(fonte);
        bitText.setCharacterSize(20);
        bitText.setString(to_string(output[j]));
        bitText.setFillColor(Color::Black);
        bitText.setPosition(x + (PADDING_CONCTOR / 15), y + 30);

        window.draw(bitText);

        CircleShape shape(5.f);
        shape.setFillColor(Color::Black);
        shape.setPosition(x, y + 65);
        window.draw(shape);
        x += (PADDING_CONCTOR / 1.5);
    }
}

void AppSimulador::painelComponentes(RenderWindow &window, Font font, vector<BUttonComponentApp> &painel) {
    vector<ComponentesApp*>::iterator it;
    Vector2f position;
    position.x = INI_COLUM_PAINEL;
    position.y = INI_LINHA_PAINEL;

    for (it = registroDeComponentes.begin(); it < registroDeComponentes.end(); it++) {

        BUttonComponentApp botao(position,font,(*it)->getNome());
        painel.push_back(botao);

        position.y += 50;

    }
}

void AppSimulador::drawPainel(RenderWindow &window, vector<BUttonComponentApp> &painel) {
    vector<BUttonComponentApp>::iterator it;

    for (it = painel.begin(); it < painel.end(); it++) {
        (*it).draw(window);
    }
}

AppSimulador::~AppSimulador() {
}
