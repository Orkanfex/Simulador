#include "Componentes.h"

AND::AND(int inputA, int inputB): inputA(inputA), inputB(inputB) {
}

void AND::simulate() {
    output = (inputA & inputB);
}

Componentes * AND::alocar() {
    return new AND(this->inputA, this->inputB);
}

int AND::getOutput() const {
    return output;
}

void AND::setInput(int inputA, int inputB) {
    inputA = inputA;
    inputB = inputB;
}

WIRE::WIRE(int inputA): input(inputA) {
}

void WIRE::simulate() {
    output = input;
}

Componentes * WIRE::alocar() {
    return new WIRE(this->input);
}

int WIRE::getOutput() const {
}