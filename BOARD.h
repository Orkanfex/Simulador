#ifndef BOARD_H
#define BOARD_H
#include "Componentes.h"
#include <vector>

using namespace std;

class BOARD {
private:
    int board[8][8];
    vector<Componentes *> componente;
public:
    BOARD();
    ~BOARD();
    void addComponentes(Componentes* componente);
    void simulate();
    void printBoard();
};

#endif //BOARD_H
