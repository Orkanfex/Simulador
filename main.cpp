#include <iostream>
#include <vector>
#include "Componente.h"
#include "Protoboard.h"

int main(int argc, char const *argv[])
{
    Protoboard pr;
    AND portAnd;

    pr.setMat(0,1,3);

    cout<<pr.getMat(0,1) << endl;
    cout<<pr.getMat(4,2) << endl;
    cout<<pr.getMat(2,6) << endl;
    
    return 0;
}
