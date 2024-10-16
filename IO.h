#ifndef IO_H
#define IO_H
#include <vector>

using namespace std;

class IO
{
private:
    vector<int> entrada;
    vector<int> saida;
public:
    IO();
    ~IO();
    void setEntrada(const vector<int> &bits);
    void setSaida(const vector<int> &bits);
    vector<int> getEntrada() const;
    vector<int> getSaida() const;
};

#endif
