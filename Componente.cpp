#include "Componente.h"

Componente::Componente()
{}

Componente::~Componente()
{}

AND *AND::alocar() {
    return new AND();
}

bool AND::operation() {
    return (inputE & inputD);    
}

void AND::setInputE(int input){
    this->inputE = input;
}

void AND::setInputD(int input){
    this->inputD = input;
}

int AND::getInputE() const{
    return this->inputE;
}

int AND::getInputD() const{
    return this->inputD;
}    