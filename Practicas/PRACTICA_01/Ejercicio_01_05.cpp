// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 22/08/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;

int main() {
    int centigrados = 0;
    cout<<"Introdusca los grados Centigrados que quiera convertir a Kelvin: "<<endl;
    cin>>centigrados;
    float kelvin=centigrados+273.15 ; //Como solo es una suma no hace falta poner una constante . ^ .
    cout<<"Su convercion de "<<centigrados<<" grados centigrados, serian "<<kelvin<<" gradps kelvin."<<endl;
    return 0;
}