// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 17/09/2025
// Número de ejercicio: 7
#include <iostream>
using namespace std;

int MCD(int x, int y);
int MCM(int a, int b); //se establecen las funciones para evitar errores en el programa al no encontrar la funcion
int main () {
    int n=0, m=0;
    do
    {
        cout<<"Ingrese un numero positivo: "<<endl;
        cin>>n;
        cout<<"Ingrese otro numero positivo: "<<endl;
        cin>>m;
        if (n<0 || m<0)
        {
            cout<<"Numeros positivos por favor"<<endl;
        }
    } while (n<0 && m<0);
    cout<<"El maximo comun divisor de los numeros que puso es: "<<MCD(n,m)<<endl;
    cout<<"El minimo comun multiplo de los numeros que puso es: "<<MCM(n,m)<<endl;
    return 0;
}
int MCD(int x, int y) {
    while (y != 0) {
        int resto = x % y;
        x = y;
        y = resto;
    }
    return x; 
}

int MCM(int a, int b) {
    return (a * b) / MCD(a, b); //es una formula simple, pero hice primero la del mcd para evitar errores
}