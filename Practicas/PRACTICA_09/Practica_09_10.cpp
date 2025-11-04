// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 10

#include <iostream>
#include <cstdlib>
using namespace std;

struct Fraccion
{
    int numerador;
    int denominador;
};

int MCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraccion ReducirFraccion(Fraccion f)
{
    Fraccion frSimplificada;
    int divisor = MCD(f.numerador, f.denominador);
    frSimplificada.numerador = f.numerador / divisor;
    frSimplificada.denominador = f.denominador / divisor;
    return frSimplificada;
}

int main()
{
    Fraccion F, FSimplificada;
    cout << "==================================================================" << endl;
    cout << "Ingrese el numerador: ";
    cin >> F.numerador;
    cout << "Ingrese el denominador: ";
    cin >> F.denominador;
    FSimplificada = ReducirFraccion(F);
    system("cls");
    cout << "==================================================================" << endl;
    cout << "\tFraccion original: " << F.numerador << "/" << F.denominador << endl;
    cout << "\tFraccion simplificada: " << FSimplificada.numerador << "/" << FSimplificada.denominador << endl;
    cout << "==================================================================" << endl;
    system("pause"); // para poder ver mejor la informacion antes de finalizar el programa
    return 0;
}
