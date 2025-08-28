// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 22/08/2025
// Número de ejercicio: 

#include <iostream>
using namespace std;

int main() {
    int num=0;
    int resultado=0;
    char respuesta='n';
    do
    {
        cout<<"Ingrese el numero del que quiera la tabla de multiplicar:"<<endl;
        cin>>num;
        for (size_t i = 1; i <= 10; i++)
        {
            resultado=num*i;
            cout<<num<<" x "<<i<<" = "<<resultado<<endl; 
        }
        cout<<"Desea calcular otra tabla? s/n "<<endl;
        cin>>respuesta;
    } while (respuesta=='s');
    cout<<"que tenga lindo dia";
    return 0;
}