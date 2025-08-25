// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 22/08/2025
// Número de ejercicio: 10

#include <iostream>
using namespace std;

int main() {
    float nota=0.00;
    cout<<"Ingrese la nota del estudiante"<<endl;
    cin>>nota;
    if (nota>=51)
    {
        if (nota>=51 && nota<=60)
        {
            cout<<"su estudiante solo aprobo";
        }
        
        else if (nota>60 && nota<=70)
        {
            cout<<"El estudiante esta aprobando, su nota es C";
        }
        else if (nota>70 && nota<=80)
        {
            cout<<"El estudiante esta aprobando, su nota es C+";
        }
        else if (nota>80 && nota<=90)
        {
            cout<<"El estudiante esta aprobando, su nota es B";
        }
        else if (nota>90 && nota<=95)
        {
            cout<<"El estudiante esta aprobando, su nota es B+";
        }
        else if (nota>95 && nota>100)
        {
            cout<<"El estudiante esta aprobando, su nota es A";
        }
        else
        {
            cout<<"El estudiante esta aprobando, su nota es A+";
        }
    }
    else
    {
        cout<<"El estudiante esta reprobando";
    }
return 0;
}