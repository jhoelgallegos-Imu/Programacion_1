// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 17 

#include <iostream>
using namespace std;

int main() {
    int num1=0, num2=0;
    int amigo1=0, amigo2=0 ;
    cout<<"Ingrese el numero que quiera verificar si es amigo:"<<endl;
    cin>>num1;
    cout<<"Ingrese el segundo numero que quiera verificar si es amigo:"<<endl;
    cin>>num2;
    for (int i = 1; i < num1; i++) //Repite la secuencia para encontar los multiplos y sumarlos para guardarlos en los amigos
    {
        if (num1 % i == 0) 
        {
            amigo1=amigo1+i;  
        }
    }
    for (int j = 1; j < num2; j++)  
    {
        if (num2 % j == 0) 
        {
            amigo2=amigo2+j;  
        }
    }
    if (amigo1==num2 && amigo2==num1)
    {
        cout<<"Los numeros son amigos :D"<<endl;
    }
    else
    {
        cout<<"Los numeros no son amigos D:"<<endl;
    }
    
    return 0;
}