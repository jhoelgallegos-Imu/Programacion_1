// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;

int par(int num1); //se declara la funcion antes del codigo principal para que el programa sepa que existe

int main () {
    int num;
    cout<<"Ingrese un numero "<<endl;
    cin>>num;
    if (par(num)==0)
    {
        cout<<"Su numero es par";
    }
    else
    {
        cout<<"Su numero es impar";
    }
    
    return 0;
}

int par(int num1){
    int resultado=0;
    resultado=num1 % 2;
    return resultado;
}