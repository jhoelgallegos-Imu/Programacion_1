// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 24/08/2025
// Número de ejercicio: 9 

#include <iostream>
using namespace std;

int main() {
    int edad=0;
    do
    {
        cout<<"Ingrese su edad porfavor: "<<endl;
        cin>>edad;
    } while (edad<=0 && edad>=125); // el "&&" hace que se le pueda dar ceirto rango a cada if  
    if (edad<=12)
    {
        cout<<"Usted es un ninno.";
    }
    else if (edad>12 && edad<=18)
    {
        cout<<"Usted es un adolecente.";
    }
    else if (edad>18 && edad<60)
    {
        cout<<"Usted es mayor de edad.";
    }
    else
    {
        cout<<"Usted es un adulto mayor.";
    }
return 0;
}