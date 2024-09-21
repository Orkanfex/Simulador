#ifndef SIMULADOR_PROTOBOARD_H
#define SIMULADOR_PROTOBOARD_H

#include <vector>
#include "Componente.h"

using namespace std;

class Protoboard
{
private:
    int N;
    int M;
    int **mat;
    vector<Componente*> componentes;

public:
    Protoboard(int, int);
    Protoboard();
    ~Protoboard();

    int getMat(int, int);
    void setMat(int, int, int);
    void insert(Componente *componente);
};

#endif