// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 19

#include <iostream>
using namespace std;

int main() {
    int num=0;
    int resultado=0;
    cout<<"Ingrese el numero del que quiera la tabla de multiplicar:"<<endl;
    cin>>num;
    for (size_t i = 1; i <= 10; i++)
    {
        resultado=num*i;
        cout<<num<<" x "<<i<<" = "<<resultado<<endl; // esta parte es mas que nada decoracion para mostrar de una mejor manera la tabla
    }
    
return 0;
}