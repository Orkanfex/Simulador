#include "WIRE.h"

WIRE::WIRE(int inX, int inY, int outX, int outY):
    inputX(inX), inputY(inY),
    outputX(outX), outputY(outY)
{}

void WIRE::simulate(int board[8][8]) {
    board[outputX][outputY] = board[inputX][inputY];
}

void WIRE::alocar() {
    // Exemplo de alocação padrão (pode ser configurada conforme necessário)
    inputX = 0; inputY = 3;
    outputX = 1; outputY = 3;
}