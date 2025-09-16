// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 15/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;

void intercambiodevalores(int& a, int& b);
int main () {
    int a,b;
    cout<<"Ingrese el numero a"<<endl;
    cin>>a;
    cout<<"Ingrese el numero b para intercambiarlo con a"<<endl;
    cin>>b;
    cout<<"El valor original de a es: "<<a<<" y el de b es: "<<b<<endl;
    intercambiodevalores(a, b);
    cout<<"Ahora el valor de a es: "<<a<<" y el de b es: "<<b<<endl;
    return 0;
}

void intercambiodevalores(int& a, int& b){
    int cambio=0;
    cambio=a;
    a=b;
    b=cambio;
}