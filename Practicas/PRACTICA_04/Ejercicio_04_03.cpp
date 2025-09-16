// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 15/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;

int ModificarValores(int& mod, int num );
int main () {
    int mod=0, n=0;
    cout<<"Ingrese el valor por referencia: "<<endl;
    cin>>mod;
    cout<<"Ingrese el valor entero: "<<endl;
    cin>>n;
    cout<<"El valor por entero ahora es: "<<ModificarValores(mod, n)<<" y el valor por referencia ahora es: "<<mod;
    return 0;
}
int ModificarValores(int& mod, int num ){
    int nuevo=0;
    mod+=10;
    nuevo=num*2;
    return nuevo;
}