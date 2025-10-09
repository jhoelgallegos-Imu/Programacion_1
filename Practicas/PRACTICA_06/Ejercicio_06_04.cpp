// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 4
// Problema planteado: Crea un programa que permita al usuario ingresar N números en un vector y luego rota
// el vector k posiciones a la derecha. Muestra el vector después de la rotación.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void RotarDerecha(vector<int> &num, int k) {
    int n = num.size();
    if (n == 0) return;
    k = k % n; // por si k > n
    for (int i = 0; i < k; i++) {
        int ultimo = num.back();  //se guarda el ultimo aparte
        num.pop_back(); //elimina el ultimo 
        num.insert(num.begin(), ultimo); //agreda el ultimo que se guardo a adelante otra vez
    }
}

int main () {
    vector<int> num;
    int n, k, temp;
    cout << "Ingrese la cantidad de datos que quiera que tenga su vector: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el dato " << i+1 << " de su vector: " << endl;
        cin >> temp;
        num.push_back(temp);
    }
    cout << "Ingrese la cantidad de vueltas que quiera dar el vector: " << endl;
    cin >> k;
    RotarDerecha(num, k);
    cout << "--------------------------------------------------" << endl;
    cout << "Vector rotado: " << endl;
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    return 0;
}
