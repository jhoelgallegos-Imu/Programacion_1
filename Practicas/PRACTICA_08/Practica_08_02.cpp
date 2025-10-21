// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 2

#include <iostream>
using namespace std; 

int PotenciaDeNumeros(int a, int n){
    if (n==0)
    {
        return 1;
    }
    else
    {
        return a*PotenciaDeNumeros(a,n-1); //se multiplican los numeros hasta que el exponente es 0 y se multiplica por uno y asi no afecta a la funcion
    }
}

int main() {
    int a, n;
    cout<<"Ingrese el numero: ";
    cin>>a;
    cout<<"Ingrese el exponente del numero: ";
    cin>>n;
    cout<<"==========================================="<<endl<<"El numero "<<a<<" elevado a "<<n<<" es igual a: "<<PotenciaDeNumeros(a,n);
    return 0;
}