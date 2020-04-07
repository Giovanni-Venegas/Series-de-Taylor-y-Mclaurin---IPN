#ifndef TAYLOR_H
#define TAYLOR_H

#include<iostream>
#include <math.h>


using namespace std;
class Taylor
{
private:
    double matriz[10][10];
    int m,n,ex,k,fac;
    double x,xo;
    double Fxo[15];
    double Fnx[15];
    double ERPA[15];

public:
        Taylor();
        ~Taylor();

        void pedirPolinomio(void);
        void derivar (void);

        void evaluarfuncion(void);
        int factorial (int k);
        void desarrolloTaylor (void);
        void errorRelativo(void);

        void muestraPoli (void);
        void muestraVector (void);
        void muestraVector2 (void);
        void muestraVector3 (void);
        void MuestraDatos(void);


        void inicializaMatriz(void);
        void inicializaVector(void);
        void inicializaVector2(void);
        void inicializaVector3(void);
        void leeMatriz (void);

};

#endif // TAYLOR_H
