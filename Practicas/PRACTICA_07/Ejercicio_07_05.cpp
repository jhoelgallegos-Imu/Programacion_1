// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 18/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int GRandom(int p, int f){
    return rand() % (f - p + 1) + p;
}

void MdeMatrices(vector<vector<int>> nxm, vector<vector<int>> mxn, vector<vector<int>> &nxn, int m, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                nxn[i][j] += nxm[i][k] * mxn[k][j]; //multiplica todo el proceso, al estar por referencia no tiene necesitas de regresar nada
            }
        }
    }
}

int main(){
    srand(time(0));
    int n = GRandom(2,5), m = GRandom(2,5);
    vector<vector<int>> matrizNxM(n, vector<int>(m));
    vector<vector<int>> matrizMxN(m, vector<int>(n));
    vector<vector<int>> matrizNxN(n, vector<int>(n, 0));
    cout << "\tMatriz A_" << n << "x" << m << ":\t" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrizNxM[i][j] = GRandom(1,10);
            cout << matrizNxM[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\tMatriz B_" << m << "x" << n << ":\t" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrizMxN[i][j] = GRandom(1,10);
            cout << matrizMxN[i][j] << "\t";
        }
        cout << endl;
    }
    MdeMatrices(matrizNxM, matrizMxN, matrizNxN, m, n);
    cout << "\nMatriz C_" << n << "x" << n << " = A*B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrizNxN[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}