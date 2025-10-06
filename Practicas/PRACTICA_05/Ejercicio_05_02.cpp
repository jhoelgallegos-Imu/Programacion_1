// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 2
#include <iostream> 
#include <vector>
using namespace std;

int main () {
    int n=3;
    float voltios[]={ 11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59 }; // esto es para los numeros ya determinados
    /*float voltio=0;
    vector<float> voltios=;
    for (int i = 0; i < 9; i++)
    {
        cout<<"Introdusca el valor "<<i+1<<"/9 ";
        cin>> voltio ;
        voltios.push_back(voltio);
    }*/
   // lo de arriva es para introducir los numeros que quiera
    for (int i = 0; i < 3; i++) // con este for se repite la secuencia de abajo 3 veces, haciendo que se impriman los 9 numeros
    {
        for (int j = n-3 ; j < n; j++) //con esto se reproducen facilmente los 9 numeros en orden
        {
            cout<<" "<<voltios[j]<<" ";
        }
        cout<<endl;
        n+=3;
    }
    return 0;
}