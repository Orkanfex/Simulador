#include "NOT.h"

NOT::NOT(int inX, int inY, int outX, int outY) :
    inputX(inX), inputY(inY),
    outputX(outX), outputY(outY)
{}

void NOT::simulate(int board[8][8]) {
    board[outputX][outputY] = !board[inputX][inputY];
}

void NOT::alocar() {
    // Exemplo de alocação padrão (pode ser configurada conforme necessário)
    inputX = 0; inputY = 2;
    outputX = 1; outputY = 2;
}

