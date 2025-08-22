// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 21/08/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;

int main() {
    int valor1=0;
    int valor2=0;
    cout<<"ingrese el valor 1: "<<endl;
    cin >>valor1;
    cout<<"ingrese el valor 2: "<<endl;
    cin >>valor2;
    if (valor1 < valor2)
    {
        cout<<valor1<<" es mayor que "<< valor2 <<endl;
    }
    else
    {
        if (valor1==valor2)
        {
            cout<<valor1<<" es igual que "<< valor2 <<endl;
        }
        else
        {
            cout<<valor1<<" es menor que "<< valor2 <<endl;
        }
    }
    return 0 ;
}
