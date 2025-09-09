// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 3
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); 
    int factorial = 1; // se empieza esta variable en 1 ya que si empezara en 0 todo acabaria como 0
    int num = (rand() % 10) + 1;
    for (int i = 1; i <=num; i++)
    {
        factorial=factorial*i; // como i va cambiando constantemente se puede usar para hacer el factorial facilmente
    }
    cout<<"El factorial de "<<num<<" es "<<factorial<<endl;
    return 0;
}