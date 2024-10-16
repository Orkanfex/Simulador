#include "IO.h"

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
