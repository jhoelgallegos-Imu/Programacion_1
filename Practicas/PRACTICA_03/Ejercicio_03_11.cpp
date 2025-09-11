// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 11
#include <iostream>
using namespace std;

double retirarDinero(double cantidad, double &saldo);

int main () {
    double saldo = 1000; //el saldo ya esta establecido como disctamino en la ordenanza
    int retiro = 0;

    do {
        cout << "Su saldo es de 1000, ingrese una cantidad multiplo de 10 para retirar" << endl;
        cin >> retiro;
        if (retiro % 10 != 0) 
            cout << "Ingrese un multiplo  de 10" << endl;
    } while (retiro % 10 != 0); //se repetira hasta que se ingrese un multiplo de 10

    cout << "Su saldo se actualizo a: " << saldo - retiro 
         << ". Por su retiro de: " << retirarDinero(retiro, saldo) << endl;

    return 0;
}

double retirarDinero(double cantidad, double &saldo) {
    saldo = saldo - cantidad;
    return cantidad;
}