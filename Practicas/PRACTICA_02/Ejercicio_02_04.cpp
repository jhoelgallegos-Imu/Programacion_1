// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 04/09/2025
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
    int intentos= 1;
    cout<<"Ingrese el numero que estoy pensando"<<endl;
    do
    {
        cout<<"Intento "<<intentos<<endl;
        cout<<"El numero esta entre "<<parametroI<<" y "<<parametroF<<endl;
        cin>>respuesta;
        if (respuesta> num && parametroF>num) // esto ayuda a que adivinar no sea tan difivil
        {
            parametroF-=5;
        }
        else if (respuesta<num && parametroI<num)
        {
            parametroI+=5;
        }
        intentos+=1;
    } while (respuesta != num);
    cout<<"Felicidades!!!!! adivinaste en el numero que estaba pensando :D";
    return 0;
}