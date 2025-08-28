// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 21

#include <iostream>
using namespace std;

int main() {
    int num1=0;
    int num2=0;
    int producto=0;
    cout<<"Ingrese los numeros que quiera multiplicar"<<endl;
    cin>>num1>>num2;
    for (size_t i = 1; i <= num1; i++) // La multiplicacion es basicamente una suma (num2), una n cantidad de veces (num1)
    {
        producto=producto+num2;
    }
    cout<<"El producto es igual a: "<<producto;
return 0;
}