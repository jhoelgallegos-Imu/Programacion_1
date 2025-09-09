// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 2
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int respuesta = 0;
    int cara = 0;
    int cruz = 0;
    float porcentajeCaras=0;
    float porcentajeCruz=0;
    cout << "Ingrese el numero de veces que quiera lanzar una moneda " << endl;
    cin >> respuesta;

    srand(time(NULL)); 

    for (int i = 1; i <= respuesta; i++) {
        int num = (rand() % 2) + 1;
        if (num % 2 == 0) {
            porcentajeCaras += 1;
        } else {
            porcentajeCruz += 1;
        }
    }
    porcentajeCaras= (porcentajeCaras * 100)/respuesta;
    porcentajeCruz= (porcentajeCruz * 100)/respuesta;
    cout << "Salieron un total de " << porcentajeCaras << "% de cara " << endl;
    cout << "Salieron un total de " << porcentajeCruz << "% de cruz" << endl;
    return 0;
}