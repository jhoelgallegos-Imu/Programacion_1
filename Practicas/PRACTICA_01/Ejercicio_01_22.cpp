// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 22 

#include <iostream>
using namespace std;

int main() {
    int num1=0,num2=0;
    cout<<"Ingrese los numeros que quiera saber si son multiplos"<<endl;
    cin>>num1>>num2;
    if (num1%num2 == 0 || num2%num1 == 0 ) // el "||" es porque me di cuenta que si primero se ingresaba el menor saltaba que no eran multiplos
    {
        cout<<"Los numeros son multiplos :D"<<endl;
    }
    else
    {
        cout<<"Los numeros no son multiplos D:"<<endl;
    }
    
return 0;
}