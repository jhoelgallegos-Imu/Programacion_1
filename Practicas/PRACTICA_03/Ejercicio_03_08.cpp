// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 8
#include <iostream>
using namespace std;

int main () {
    int money;
    cout << "Ingrese el valor que quiera retirar en billetes/monedas: ";
    cin >> money;
    int c200 = 0, c100 = 0, c50 = 0, c20 = 0, c10 = 0;
    int m1 = 0, m2 = 0, m5 = 0;
    while (money >= 200) {
        c200++;
        money -= 200;
    }
    while (money >= 100) {
        c100++;
        money -= 100;
    }
    while (money >= 50) {
        c50++;
        money -= 50;
    }
    while (money >= 20) {
        c20++;
        money -= 20;
    }
    while (money >= 10) {
        c10++;
        money -= 10;
    }
    while (money >= 5) {
        m5++; // Investigando descubri que con esto a una variable igual se le suma 1 mas 
        money -= 5;
    }
    while (money >= 2) {
        m2++;
        money -= 2;
    }
    while (money >= 1) {
        m1++;
        money -= 1;
    }
    if (c200 > 0) cout << c200 << " billetes de 200 Bs." << endl;
    if (c100 > 0) cout << c100 << " billetes de 100 Bs." << endl; //asi ocupa menos espacio en el codigo
    if (c50  > 0) cout << c50  << " billetes de 50 Bs."  << endl;
    if (c20  > 0) cout << c20  << " billetes de 20 Bs."  << endl;
    if (c10  > 0) cout << c10  << " billetes de 10 Bs."  << endl;
    if (m5  > 0) cout << m5  << " monedas de 5 Bs."  << endl;
    if (m2  > 0) cout << m2  << " monedas de 2 Bs."  << endl;
    if (m1  > 0) cout << m1  << " monedas de 1 Bs."  << endl;
    return 0;
}
