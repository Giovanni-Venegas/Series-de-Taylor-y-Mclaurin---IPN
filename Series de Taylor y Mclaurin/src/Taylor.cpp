#include "Taylor.h"

Taylor::Taylor()
{
    //ctor
}

Taylor::~Taylor()
{
    //dtor
}
void Taylor::inicializaMatriz(void){
    for(int i=0; i <n+1; i++)
        for(int j=0; j<(m+1)*2; j++)
        matriz[i][j] = 0.0;
}
void Taylor::inicializaVector(){
    for(int i=0; i <n+1; i++)
        Fxo[i] = 0.0;
}
void Taylor::inicializaVector2(){
    for(int i=0; i <n+1; i++)
        Fnx[i] = 0.0;
}
void Taylor::inicializaVector3(){
for(int i=0; i <n+1; i++)
        ERPA[i] = 0.0;
}
void Taylor::pedirPolinomio (void){

    double v;
    cout<<"Ingrese el grado del polinomio m: "<<endl;
    cin>>m;

    cout<<"Ingrese el grado de aproximacion de Taylor: "<<endl;
    cin>>n;
    cout<<"Ingrese el punto de origen x0: "<<endl;
    cin>>xo;
    cout<<"Ingrese el punto a evaluar: "<<endl;
    cin>>x;
    inicializaMatriz();
    leeMatriz();

}
void Taylor::leeMatriz (void){
    ex=m;
    double v;
    cout<<"Ingresa polinomio: "<<endl;
     for(int i=0;i<1;i++){
        for(int j=0;j<(m+1)*2;j++){
            cout<<"x^"<<ex<<"=";
            cin>>v;
            matriz[i][j]=v;
            j++;
            matriz[i][j]=ex;
            ex--;
        }
    }
}

void Taylor::derivar (void){
    for(int i=0; i<(n+1); i++){
		for(int j=0; j<(m+1)*2; j++){
			matriz[i+1][j]=matriz[i][j+1]*matriz[i][j];

			if(matriz[i][j+1]==0)
				matriz[i+1][j+1]=0;
			else
				matriz[i+1][j+1]=matriz[i][j+1]-1;
			j++;
		}
	}

}
 int Taylor::factorial (int k){
fac=1;
    if(k==0){
    fac=1;
        return fac;
 }else{
     for(int j=1; j<=k; j++){
			fac=fac*j;
		}
        return fac;
 }
 }

void Taylor::muestraPoli (void){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<(m+1)*2;j++){
            cout<<"["<<i<<","<<j<<"]="<<matriz[i][j]<<endl;
        }
    }
}




void Taylor::evaluarfuncion(){
    double s=0;
    inicializaVector();
    for(int i=0; i<1; i++){
		for(int j=0; j<(m+1)*2; j++){
			s=s+matriz[i][j]*pow(x,matriz[i][j+1]);
			j++;
		}
	}
    for(int i=0; i<(n+1); i++)
		Fxo[i]=s;
}

void Taylor::desarrolloTaylor(void){
    double s=0;
    inicializaVector2();
    for(int i=0; i<(n+1); i++){
		for(int j=0; j<(m+1)*2; j++){
			s=s+((matriz[i][j]*pow(xo,matriz[i][j+1]))/factorial(i))*pow(x-xo,i);
			j++;
		}
		Fnx[i]=s;
	}
}
void Taylor::errorRelativo(void){
    inicializaVector3();
	for(int i=0; i<(n+1); i++){
		ERPA[i]=(fabs((Fxo[i]-Fnx[i])/Fxo[i]))*100;
	}
}

void Taylor::muestraVector (void){
    for(int i=0;i<n+1;i++){
        cout<<i<<"="<<Fxo[i]<<endl;
    }
}
void Taylor::muestraVector2 (void){
    for(int i=0;i<n+1;i++)
        cout<<i<<"="<<Fnx[i]<<endl;
}
void Taylor::muestraVector3 (void){
    for(int i=0;i<n+1;i++){
        cout<<i<<"="<<ERPA[i]<<endl;
    }}

void Taylor::MuestraDatos(void){
	cout<<"Su funcion es:"<<endl;
	for(int i=0; i<1; i++){
		for(int j=0; j<(m+1)*2; j++){
			if(matriz[i][j]!=0){
					if(matriz[i][j+1]==0)
						cout<<matriz[i][j];
					else if(matriz[i][j+1]==1)
						cout<<matriz[i][j]<<"x";
					else
						cout<<matriz[i][j]<<"x^"<<matriz[i][j+1];
				}

			if(matriz[i][j+1]!=0){
				if(matriz[i][j+2]<0)
					cout<<"";
				else if(matriz[i][j+2]>0)
					cout<<"+";
			}
			j++;
		}
	}

	cout<<endl<<endl<<"La serie de Taylor es....."<<endl<<endl;

	cout<<"Grado de aprox."<<"\t"<<"f(x)"<<"\t"<<"fn(x)"<<"\t"<<"Et"<<"\t";
	cout<<endl;
	for(int i=0; i<(n+1); i++){
		cout<<"\t"<<i<<"\t"<<Fxo[i]<<"\t"<<Fnx[i]<<"\t"<<ERPA[i]<<"\t";
		cout<<endl;
	}
}

