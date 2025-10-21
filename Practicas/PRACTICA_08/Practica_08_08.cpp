// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 8

#include <iostream>
using namespace std;

void Ullman(int n) {
    cout << n << " "; 
    if (n == 1)
        return; 
    if (n % 2 == 0)
        Ullman(n / 2);     
    else
        Ullman(3 * n + 1); 
}

int main() {
    int n;
    do
    {
        cout << "Ingrese un numero entero positivo mayor que 1: ";
        cin >> n;
        if (n<=1) // se verifica, para que no se vea repetidamente limpio la terminal como el cin
        {
            system("cls");
            cout<<"SELECCIONE UNA DIFERENTE O MAYOR A UNO PORFAVOR"<<endl;
            cin.clear();
        }
    } while (n<=1);
    cout << "Secuencia de Ullman: ";
    Ullman(n); 
    cout << endl;
    return 0;
}