// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 18/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int GRandom(int p, int f){
    return rand() % (f - p + 1) + p;
}

int sumaUltimaColumna(const vector<vector<int>>& m, int n){
    int suma = 0;
    for (int i = 0; i < n; i++){ //recorre la ultima columna y suma sus digitos
        suma += m[i][n - 1];
    }
    return suma;
}

int productoUltimaFila(const vector<vector<int>>& m, int n){
    int producto = 1; //se empieza en 1 pq si empezara en 0 todo terminaria siendo 0
    for (int j = 0; j < n; j++){ //recorre la ultima fila y saca el producto de sus digitos
        producto *= m[n - 1][j];
    }
    return producto;
}

float desviacionEstandar(const vector<vector<int>>& m, int n){
    float suma = 0;
    int total = n * n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            suma += m[i][j];
        }
    }
    float media = suma / total;
    float sumaCuadrados = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sumaCuadrados += pow(m[i][j] - media, 2);
        }
    }
    float DE = sqrt(sumaCuadrados / total);
    return DE;
}

int main(){
    srand(time(0));
    int n, a, b;
    cout << "Ingrese el tamano de la matriz cuadrada: ";
    cin >> n;
    cout << "Ingrese el limite inferior: ";
    cin >> a;
    cout << "Ingrese el limite superior: ";
    cin >> b;
    vector<vector<int>> matriz(n, vector<int>(n));
    int Vmayor = a, pi = 0, pj = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz[i][j] = GRandom(a, b);
            if (matriz[i][j] > Vmayor){
                Vmayor = matriz[i][j];
                pi = i + 1;
                pj = j + 1;
            }
        }
    }
    cout << "\nMatriz generada:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nLa suma de la ultima columna es: " << sumaUltimaColumna(matriz, n) << endl;
    cout << "El producto total de la ultima fila es: " << productoUltimaFila(matriz, n) << endl;
    cout << "El valor mas grande en la matriz es: " << Vmayor
         << " que esta en: (" << pi << "," << pj << ")" << endl;
    cout << "La desviacion estandar de la matriz es: " << desviacionEstandar(matriz, n) << endl;
    return 0;
}
