#include "BOARD.h"
#include <iostream>

using namespace std;

BOARD::BOARD() {
    int x = 225, y;
    for(int i = 0; i < 8; i++) {
        y = 150;
        for(int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
}

BOARD::~BOARD() {
    for (auto comp : componente) {
        delete comp;
    }
}

void BOARD::addComponentes(Componentes *component) {
    componente.push_back(component);
    component->alocar();
}

void BOARD::simulate() {
    for(auto comp : componente) {
        comp->simulate(board);
    }
}

void BOARD::printBoard() {
    cout << "Estado atual da palca\n";

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

