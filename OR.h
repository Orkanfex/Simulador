#ifndef OR_H
#define OR_H

#include "Componentes.h"
using namespace std;


class OR : public Componentes {
private:
    int input1X, input1Y;  // Coordenadas do primeiro ponto de entrada
    int input2X, input2Y;  // Coordenadas do segundo ponto de entrada
    int outputX, outputY;  // Coordenadas do ponto de saída
public:
    OR(int in1X, int in1Y, int in2X, int in2Y, int outX, int outY);
    void simulate(int board[8][8]) override;
    void alocar() override;
};

#endif // OR_H