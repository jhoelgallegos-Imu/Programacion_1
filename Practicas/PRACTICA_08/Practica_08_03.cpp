// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); //toma los 2 ultimos digitos y los suma
}

int main() {
    int n;
    cout << "Ingrese la posicion n (entero no negativo): ";
    cin >> n;
    cout << "El numero de Fibonacci en la posicion " << n << " es: " << fibonacci(n) << endl;
    return 0;
}