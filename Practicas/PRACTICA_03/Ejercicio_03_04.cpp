// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;

float IMC(float peso, float altura);

int main () {
    float peso=0, altura = 0;
    cout<<"Ingrese su peso"<<endl;
    cin>>peso;
    cout<<"Ingrese su altura"<<endl;
    cin>>altura;
    cout<<"El Indice de masa corporal es "<<IMC(peso,altura);
    return 0;
}

float IMC(float peso, float altura) {
    float resultado = 0 ;
    resultado= peso /((altura)*(altura)); // para hacerlo facil solo use la formula
    return resultado;
}
