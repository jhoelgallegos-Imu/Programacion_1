// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 6
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    srand(time(NULL));
    int respuesta = 0 ; 
    int primos=0;
    cout<<"Cuantos numeros aleatorios quiere generar? "<<endl;
    cin>>respuesta;
    for (int i = 1; i <= respuesta; i++)
    {
        int num = (rand() % 10000) + 1;
        int primoscont = 0;
        cout<<num<<" - ";
        for (int j = 2; j <= sqrt(num); j++) // ayuda a que no sea tan lento al probar desde su raiz para que no sea tan tardado
        {
            if (num % j == 0)
            {
                primoscont+=1;
                break;
            }
        }
        if (primoscont==0 && num!=1)
        {
            primos+=1;
        }
    }
    cout<<"\n Los numeros primos en total que salieron fueron "<<primos;
    return 0;
}