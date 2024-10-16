#include "Alocar.h"
#include <iostream>

Alocar::Alocar() {
    // Inicializa a protoboard com valores 0
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = 0;
}

void Alocar::adicionarComponente(Componentes* componente) {
    componente->alocar();  // Chama o método de alocação do componente
    componentes.push_back(componente);
}

void Alocar::simular() {
    // Simula o comportamento de todos os componentes
    for (auto componente : componentes) {
        componente->simulate(board);
    }
}

void Alocar::imprimirBoard() {
    // Imprime o estado atual da protoboard
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}