#include "OR.h"

OR::OR(int in1X, int in1Y, int in2X, int in2Y, int outX, int outY) :
    input1X(in1X), input1Y(in1Y),
    input2X(in2X), input2Y(in2Y),
    outputX(outX), outputY(outY)
{}

void OR::simulate(int board[8][8]) {
    board[outputX][outputY] = board[input1X][input1Y] && board[input2X][input2Y];
}

void OR::alocar() {
    // Exemplo de alocação padrão (pode ser configurada conforme necessário)
    input1X = 0; input1Y = 1;
    input2X = 1; input2Y = 1;
    outputX = 2; outputY = 1;
}