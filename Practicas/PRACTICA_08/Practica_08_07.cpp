// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 7

#include <iostream>
using namespace std;

int Q(int n) {
    if (n == 1)
        return 1;           
    else
        return n * n + Q(n - 1);  //se usa la formula quitando el mas grande y restando 1 hasta que llegue a 1 y devuelve todo
}
int main() {
    int n;
    cout << "Ingrese un numero entero positivo: ";
    cin >> n;
    cout << "Q(" << n << ") = " << Q(n) << endl;
    return 0;
}