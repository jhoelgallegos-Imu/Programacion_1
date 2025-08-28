// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 20

#include <iostream>
using namespace std;

int main() {
    long long num=0; //el long long es pq si solo pongo int solo cuenta hasta 10
    int digitos=0;
    cout<<"Ingresar el numero que quiere calcular los digitos"<<endl;
    cin>>num;
    while (num!=0)
    {
        digitos += 1;
        num = num / 10;
    }
    cout<<"Los digitos de tu numero es igual a "<<digitos<<endl;
return 0;
}