// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 26/08/2025
// Número de ejercicio: 15

#include <iostream>
using namespace std;

int main() {                    
    float PromNotas=0;
    float notas=0;
    int cantidad=0;
    cout<<"Ingrese la cantidad de notas que quiera ingresar"<<endl;
    cin>>cantidad; //Puse esta parte ya que en el ejercicio no se preestablecen la cantidad de notas
    for (size_t i = 1; i <= cantidad; i++)
    {
        cout<<"Ingrese la "<<i<<" nota"<<endl;
        cin>>notas;
        PromNotas=PromNotas+notas;
    }
    PromNotas=PromNotas/cantidad;
    cout<<"El promedio de las notas seria: "<<PromNotas;
return 0;
}
