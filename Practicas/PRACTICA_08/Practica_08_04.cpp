// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 4

#include <iostream>
using namespace std;

int MCD(int a, int b) {
    if (b == 0)
        return a;          
    else
        return MCD(b, a % b); // se va sacando el mod de cada uno hasta que alguno de los 2 de 0
}

int main() {
    int a, b;
    cout << "Ingrese dos numeros enteros positivos: "<<endl;
    cin >> a >> b;
    cout << "El maximo comun divisor de " << a << " y " << b << " es: " << MCD(a, b) << endl;
    return 0;
}