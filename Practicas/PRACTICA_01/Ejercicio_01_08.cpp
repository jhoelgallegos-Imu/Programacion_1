// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 24/08/2025
// Número de ejercicio: 8 

#include <iostream>
using namespace std;

int main() {
    int num=0;
    cout<<"Ingrese un numero por favor: "<<endl;
    cin>>num;
    if (num % 2 ==0) // EL "%" es para sacar el resto de una division
    {
        cout<<"el numero es par";
    }
    else
    {
        cout<<"El numero es impar";
    }
    
return 0;
}