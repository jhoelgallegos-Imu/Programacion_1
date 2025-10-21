// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
using namespace std;

bool sonIguales(const vector<int>& v1, const vector<int>& v2, int n) {                
    if (n == 0)
        return true;    //si ya no hay elementos a comparar devuelve verdadero              
    else if (v1[n - 1] != v2[n - 1])
    {
        return false;   //si hay un valor diferente regresa falso 
    }                
    return sonIguales(v1, v2, n - 1); 
}

int main() {
    int n;
    cout << "Ingrese el tamanio de los vectores: ";
    cin >> n;
    vector<int> v1(n), v2(n);
    cout << "Ingrese los elementos del primer vector:" << endl;
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    cout << "Ingrese los elementos del segundo vector:" << endl;
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    if (sonIguales(v1, v2, n))
        cout << "Los vectores son iguales :D" << endl;
    else
        cout << "Los vectores son diferentes D:" << endl;
    return 0;
}