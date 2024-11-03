//
// Created by madeira on 02/11/24.
//

#ifndef APPSIMULADOR_H
#define APPSIMULADOR_H

#include <vector>
#include "ComponentesApp.h"
#include "CalcLogico.h"
#include  <SFML/Graphics.hpp>

#define INI_LINHA_PAINEL 100;
#define INI_COLUM_PAINEL 30;
#define INIT_PROTO_X 225
#define INIT_PROTO_Y 150
#define SIZE_PROTOBOARD 400
#define PADDING_CONCTOR 50

using namespace sf;

class AppSimulador {
    vector<ComponentesApp*> registroDeComponentes;
    CalcLogico simular;
    int board[8][8];
    vector<int> input;
    vector<int> output;

    RectangleShape shape;
    Text label;
    bool isDragging;

public:
    AppSimulador();
    void registraComponente(ComponentesApp*);
    void mainDoApp();
    void configureButtonsInput(vector<RectangleShape> &botoes, Font fonte, vector<Text> &text);
    void plotEntradaBIts(RenderWindow &windows, vector<RectangleShape> &botoes, Font font);
    void plotSaidaBits(RenderWindow &window, Font font);
    void painelComponentes(RenderWindow &window, Font font);
    ~AppSimulador();
};



#endif //APPSIMULADOR_H
