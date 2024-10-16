#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "WIRE.h"
#include "Alocar.h"

int main() {
    Alocar alocador;

    // Criação de componentes lógicos
    AND andGate(0, 0, 1, 0, 2, 0);
    OR orGate(0, 0, 1, 1, 2, 1);
    NOT notGate(0, 0, 2, 2);
    WIRE wire(0, 0, 1, 1);

    // Adiciona os componentes ao alocador e os aloca
    alocador.adicionarComponente(&andGate);
    alocador.adicionarComponente(&orGate);
    alocador.adicionarComponente(&notGate);
    alocador.adicionarComponente(&wire);

    // Executa a simulação
    alocador.simular();

    // Exibe o estado da protoboard
    alocador.imprimirBoard();

    return 0;
}
