
#include "Protoboard.h"

Protoboard::Protoboard(int N = 8, int M = 8): N(N), M(M){
    mat = new int* [N];

    for (int i = 0; i < M; i++)
    {
        mat[i] = new int [M];
    }
}

Protoboard::Protoboard(): N(8), M(8){
    mat = new int* [N];

    for (int i = 0; i < M; i++)
    {
        mat[i] = new int [M];
    }
}

void Protoboard::insert(Componente *componente){
    componentes.push_back(componente->alocar());
}

Protoboard::~Protoboard(){
    vector<Componente*>::iterator it;

    for (it = componentes.begin(); it != componentes.end(); it++)
    {
        delete *it;
    }
}

int Protoboard::getMat(int N, int M){
    return this->mat[N][M];
}

void Protoboard::setMat(int N, int M, int key){
    this->mat[N][M] = key;
}