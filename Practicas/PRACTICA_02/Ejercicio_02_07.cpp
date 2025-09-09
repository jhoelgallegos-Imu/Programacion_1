// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería en Multimedia e Interactividad
// Fecha creación: 09/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL)); 
    int respuesta = 0;
    int ninnos1 = 0;
    int ninnos2 = 0;
    int ninnos3 = 0;
    int ninnosT = 0;

    cout << "Ingrese la cantidad de ninnos que hay en la guarderia: " << endl;
    cin >> respuesta;
    ninnos1 = rand() % (respuesta + 1); //Apartir de la generacion de los ninnos de 1 anno se general los demas para evitar que sobrepaso los que se establecio previamente              
    ninnos2 = rand() % (respuesta - ninnos1 + 1);       
    ninnos3 = respuesta - ninnos1 - ninnos2;           
    ninnosT = (ninnos1 * 6) + (ninnos2 * 3) + (ninnos3 * 2);
    cout << "La cantidad de panales usados en total seria: " << ninnosT << endl;
    return 0;
}
