// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); 
    int respuesta=0;
    int promedio=0;
    int sumatoria=0;
    int max=0;
    int min=1000; // Esta inicialisado de esta manera ya que si empieza en 0 ningun numero sera menor que ese
    cout<<"Ingrese el numero aleatorios que quisiera sacar el promedio, sumatoria, el mayor y el menor"<<endl;
    cin>>respuesta;
    for (int i = 1; i <= respuesta; i++)
    {
        int num = (rand() % 1000) + 1;
        sumatoria= sumatoria + num;
        if (num > max)
        {
            max=num;
        }
        else if (num<min)
        {
            min=num;
        }
    }
    promedio= sumatoria/respuesta;
    cout<<"La sumatoria de los numeros aleatorios generados es "<<sumatoria<<endl;
    cout<<"El promedio de los numeros aleatorios generados es "<<promedio<<endl;
    cout<<"El numero maximo de los numeros aleatorios generados es "<<max<<endl;
    cout<<"El numero mas bajo de los numeros aleatorios generados es "<<min<<endl;
    return 0;
}