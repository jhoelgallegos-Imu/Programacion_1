// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 26/08/2025
// Número de ejercicio: 13

#include <iostream>
using namespace std;

int main() {
    int num=0;
    int nsum=0;
    cout<<"Ingrese un numero"<<endl;
    cin>>num;
    nsum=(num*(num+1))/2;
    cout<<"La suma de todos los numeros hasta "<<num<<" es "<<nsum<<endl;
    return 0;
}
