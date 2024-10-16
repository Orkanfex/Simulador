#ifndef AND_H
#define AND_H
#include "Componentes.h"

class AND : public Componentes{
private:
    int input1X, input1Y;
    int input2X, input2Y;
    int outputX, outputY;
public:
    AND(int, int, int, int, int, int);
    void simulate(int board[8][8]) override;
    void alocar() override;
};


#endif //AND_H
