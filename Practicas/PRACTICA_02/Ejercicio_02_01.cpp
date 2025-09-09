// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 04/09/2025
// Número de ejercicio: 1

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int respuesta = 0;
    int pares = 0;
    int impares = 0;

    cout << "Ingrese el numero de veces que quiera girar el dado" << endl;
    cin >> respuesta;

    srand(time(NULL)); //el inicializador se hace una vez antes ya que si se hace dentro del for se repetiria la semilla 

    for (int i = 1; i <= respuesta; i++) {
        int num = (rand() % 6) + 1;
        if (num % 2 == 0) {
            pares += 1;
        } else {
            impares += 1;
        }
        //cout<<num<<endl;  esta parte es por si se quiere ver el numero que sale
    }

    cout << "Salieron un total de " << pares << " caras pares" << endl;
    cout << "Salieron un total de " << impares << " caras impares" << endl;
    return 0;
}
