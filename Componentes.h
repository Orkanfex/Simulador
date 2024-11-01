#ifndef COMPONENTES_H
#define COMPONENTES_H

class Componentes {
public:
    virtual ~Componentes() = default;
    virtual void simulate(int board[8][8]) = 0;
    virtual void alocar() = 0;
};

class AND : public Componentes{
private:
    int output;
    int input[8];
public:
    AND();
    void simulate(int board[8][8]) override;
    void alocar() override;
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
    int input[8];
public:
    WIRE();
    void simulate(int board[8][8]) override;
    void alocar() override;
};

#endif //COMPONENTES_H
