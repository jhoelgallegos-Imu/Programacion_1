// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
using namespace std;

int sumaVector(const vector<int>& v, int n) {
    if (n == 1) 
        return v[0];                
    else 
        return v[n - 1] + sumaVector(v, n - 1); //va extrallendo poco a poco los elementos del arreglo hasta que quede vacio, cuando se acaban se suman
}

int main() {
    int n;
    cout << "Ingrese el tamanio del vector: ";
    cin >> n;
    vector<int> numeros(n);
    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    cout << "La suma de los elementos es: " << sumaVector(numeros, n) << endl;
    return 0;
}