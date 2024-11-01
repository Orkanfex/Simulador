#include "IO.h"

IO::IO() {
    for (int i = 0; i < 8; i++) {
        bitsEntrada[i] = 0;
        bitsSaida[i] = 0;
    }
}

IO::~IO() {

}
void IO::setEntrada(int bit, int indice) {
    bitsEntrada[indice] = bit;
}

void IO::setSaida(int bit, int indice) {
    bitsSaida[indice] = bit;
}

int IO::getEntrada(int indice) const{
    return bitsEntrada[indice];
}

int IO::getSaida(int indice) const {
    return  bitsSaida[indice];
}
