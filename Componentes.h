#ifndef COMPONENTES_H
#define COMPONENTES_H

class Componentes {
public:
    virtual ~Componentes() = default;
    virtual void simulate() = 0;
    virtual Componentes* alocar() = 0;
};

class AND : public Componentes{
private:
    int output;
    int inputA;
    int inputB;
public:
    AND(int inputA = 0, int inputB = 0);

    int getOutput() const;
    void setInput(int inputA, int inputB);
    void simulate();
    Componentes *alocar();
};

// class NOT :public Componentes {
// private:
//     int output;
//     int input[8];
// public:
//     NOT();
//     void simulate(int board[8][8]) override;
//     void alocar() override;
// };
//
// class OR : public Componentes {
// private:
//     int output;
//     int input[8];
// public:
//     OR();
//     void simulate(int board[8][8]) override;
//     void alocar() override;
// };

class WIRE :public Componentes {
private:
    int output;
    int input;
public:
    WIRE(int inputA = 0);
    int getOutput() const;
    void simulate();
    Componentes *alocar();
};

#endif //COMPONENTES_H
