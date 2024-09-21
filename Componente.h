#ifndef SIMULADOR_COMPONENTE_H
#define SIMULADOR_COMPONENTE_H

class Componente
{
public:
    virtual Componente* alocar() = 0;
    virtual bool operation() = 0;
    Componente();
    virtual ~Componente();
};

class AND: private Componente
{
private:
    int output;
    int inputE;
    int inputD;
public:

    AND* alocar();
    bool operation();
    
    void setInputE(int);
    void setInputD(int);
    int getInputE() const;
    int getInputD() const;
};

#endif