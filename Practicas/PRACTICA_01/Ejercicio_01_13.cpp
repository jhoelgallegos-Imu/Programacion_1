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
    for (size_t i = 0; i <= num; i++) //el for hace que se pueda repetir la secuencia y se sume consecutivamente
    {
        nsum=nsum+i;
    }
    cout<<"La suma de sus numeros es: "<<nsum;
    return 0;
}
