#include "IO.h"

IO::IO() {
    for (int i = 0; i<8; i++)
        entrada.push_back(0);
}

IO::~IO() {
    for (int i = 0; i<8; i++)
        entrada.pop_back();
}
void IO::setEntrada(const vector<int> &bits) {
    entrada = bits;
}

void IO::setSaida(const vector<int> &bits) {
    saida = bits;
}

vector<int> IO::getEntrada() const{
    return entrada;
}

vector<int> IO::getSaida() const {
    return  saida;
}
