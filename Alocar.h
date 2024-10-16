#ifndef ALOCAR_H
#define ALOCAR_H

#include "Componentes.h"
#include <vector>
using namespace std;

class Alocar {
private:
    int board[8][8];  // Representa o estado da protoboard
    vector<Componentes*> componentes;  // Lista de componentes alocados

public:
    Alocar();
    void adicionarComponente(Componentes* componente);
    void simular();
    void imprimirBoard();
};

#endif //ALOCAR_H
