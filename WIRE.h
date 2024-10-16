#ifndef WIRE_H
#define WIRE_H
#include "Componentes.h"

class WIRE :public Componentes {
private:
    int inputX, inputY;
    int outputX, outputY;
public:
    WIRE(int, int, int, int);
    void simulate(int board[8][8]) override;
    void alocar() override;
};

#endif //WIRE_H
