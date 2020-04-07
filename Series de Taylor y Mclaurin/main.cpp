#include <iostream>

#include "Taylor.h"
using namespace std;

int main()
{

    Taylor obj;

    obj.pedirPolinomio();
    obj.derivar();
    obj.evaluarfuncion();
    obj.desarrolloTaylor();
    obj.errorRelativo();
    cout<<endl<<endl;
    obj.MuestraDatos();



    return 0;
}
