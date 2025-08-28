// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 18

#include <iostream>
using namespace std;

int main() {
    bool primo = true;
    for (int n = 1; n <= 100; n++) 
    {
        if (n <= 1) continue; //El continue hace que si es verdad que se lo salte  
        for (int i = 2; i < n; i++) 
        {
            if (n % i == 0) 
            {
                primo = false;
                break;
            }
        }

        if (primo) 
        {
            cout << n << " ";
        }
    }
    cout << endl;
    return 0;
}