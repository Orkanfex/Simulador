#ifndef COMPONENTES_H
#define COMPONENTES_H

class Componentes {
public:
    virtual ~Componentes() = default;
    virtual void simulate(int board[8][8]) = 0;
    virtual void alocar() = 0;
};


#endif //COMPONENTES_H
