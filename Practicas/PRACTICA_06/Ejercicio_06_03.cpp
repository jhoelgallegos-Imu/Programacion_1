// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 7/10/2024
// Número de ejercicio: 3
/* Problema planteado: Se tiene 3 vectores de 10 elementos cada uno:
            • Vector de nombres.
            • Vector Apellidos
            • Vector de Edad
Seleccione 1 nombre, 1 apellido y una edad al azar y despliegue en pantalla.
Esto debe realizar N veces.*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int min, int max){ // codigo para generar numeros randoms
    return rand() % (max - min) + min;
}

int main () {
    srand(time(0));
    vector<string> nombres = {"Araceli", "Geral", "Patricia", "Lorena", "Javier", "Nathan", "Nestor", "Tracey", "Marshal", "Barney"};
    vector<string> apellidos = {"Gallegos", "Mamani", "Chipana", "Torrez", "Marinno", "Mosby", "Stinson", "Turner", "Joestar", "Casas"};
    vector<int> edades = {22,16,18,19,22,14,25,29,30,100};
    int n;
    cout << "Ingrese el numero de secuencias que quiera crear " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) //se crean las secuencias que se pida en n
    {
        cout << "nombre " << nombres[random(0,10)]<< " //Apellido " << apellidos[random(0,10)]<< " //edad: " << edades[random(0,10)] << endl;
    }
    return 0;
}
