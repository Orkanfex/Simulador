#ifndef IO_H
#define IO_H
#include <vector>

using namespace std;

class IO
{
private:
    int bitsEntrada[8];
    int bitsSaida[8];
public:
    IO();
    ~IO();
    void setEntrada(int bit, int indice);
    void setSaida(int bit, int indice);
    int getEntrada(int indice) const;
    int getSaida(int indice) const;
};

#endif
