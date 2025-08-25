// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 24/08/2025
// Número de ejercicio: 7

#include <iostream>
using namespace std;

int main() {
    char letra='a';
    cout<<"Ingrese algun caracter por favor: "<<endl;
    cin>>letra;
    if (letra=='a' || letra=='e' || letra=='i'|| letra=='o' || letra=='u')
    { //los "||" son ors para que pueda tener varios parametros para evali=uar los if
        cout<< "Tu letra es una vocal. "<<endl;
    } // decidi primero evaluar los caracter especiales pq en el ascci estan mezcladas vocales y consonantes
    else if (letra>=33 || letra>=47 || letra>=58 || letra<=64 || letra>=123 || letra<=254) 
    {
        cout<<"lo que ingresaste es un caracter especial. "<<endl;
    }
    else
    {
        cout<<"Tu letra ingresada es una consonante. "<<endl;
    }
return 0;
}