// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 26/08/2025
// Número de ejercicio: 14

#include <iostream>
using namespace std;

int main() {
    int num=4;
//    cin>>num;   //Si se quita el comentario de esta parte se puede seleccionar que tan larga quisiera la piramide
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
return 0;
}
