#include "AND.h"

AND::AND(int in1X, int in1Y, int in2X, int in2Y, int outX, int outY) :
        input1X(in1X), input1Y(in1Y),
        input2X(in2X), input2Y(in2Y),
        outputX(outX), outputY(outY)
{}

void AND::simulate(int board[8][8]) {
        // Faz a operação AND entre os dois pontos de entrada e atribui ao ponto de saída
        board[outputX][outputY] = board[input1X][input1Y] && board[input2X][input2Y];
}

void AND::alocar() {
        // Exemplo de alocação padrão (pode ser configurada conforme necessário)
        input1X = 0; input1Y = 0;
        input2X = 1; input2Y = 0;
        outputX = 2; outputY = 0;
}


