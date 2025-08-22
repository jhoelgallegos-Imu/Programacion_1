// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 21/08/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;

int main() {
    int base=0;
    int altura=0;
    cout<<"ingrese la base del triangulo: "<<endl;
    cin >>base;
    cout<<"ingrese la altura del triangulo: "<<endl; 
    cin >>altura;              // esta parte es repetida del ejercicio 2 para poder elegir diferentes balores para la altura y la base  
    int area=(base*altura)/2; //aqui esta la formula para calcular el area de un triangulo
    cout<<"El area del triangulo es: "<<area;                       
    return 0 ;
}