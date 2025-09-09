// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 4
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); 
    int num = (rand() % 50) + 1;
    int respuesta=0;
    int parametroF=50;
    int parametroI=0;
    cout<<"Ingrese el numero que estoy pensando"<<endl;
    for (int i = 1; i <=5; i++)
    {
        cout<<"Intento "<<i<<endl;
        cout<<"El numero esta entre "<<parametroI<<" y "<<parametroF<<endl;
        cin>>respuesta;
        if (respuesta> num && parametroF>num) // esto ayuda a que adivinar no sea tan difivil
        {
            parametroF-=10;
        }
        else if (respuesta<num && parametroI<num)
        {
            parametroI+=10;
        }
    }
    
    cout<<"Felicidades!!!!! adivinaste en el numero que estaba pensando :D";
    return 0;
}