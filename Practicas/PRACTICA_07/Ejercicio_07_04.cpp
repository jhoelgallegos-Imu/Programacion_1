// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 18/10/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generarMatrizOrdenada(int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor;
            valor++; 
        }
    }
    return matriz;
}

void mostrarMatriz(vector<vector<int>> matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el orden de la matriz (n): ";
    cin >> n;
    vector<vector<int>> matriz = generarMatrizOrdenada(n);
    cout << "\n Matriz ordenada de " << n << "x" << n << ":\n";
    mostrarMatriz(matriz);
    return 0;
}