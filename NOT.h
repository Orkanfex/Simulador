#ifndef NOT_H
#define NOT_H
#include "Componentes.h"

class NOT :public Componentes {
private:
    int inputX, inputY;
    int outputX, outputY;
public:
    NOT(int, int, int, int);
    void simulate(int board[8][8]) override;
    void alocar() override;
};

#endif //NOT_H

