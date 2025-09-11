// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 9
#include <iostream>
using namespace std;

int horasextra = 0;
float convercion(float t, int &horasextra);

int main () {
    float time = 0;
    cout << "Cuanto tiempo ha trabajado (Ingrese en minutos):" << endl;
    cin >> time;

    float horas = convercion(time, horasextra);

    if (horas > 8) {
        cout << "Usted trabajo 8 horas con " << horasextra << " de horas extra." << endl;
    }
    else if (horas < 8) {
        float resto = 8 - horas;
        cout << "Usted no completo su jornada laboral, solo hizo " << horas 
             << " horas. Le debe a la empresa " << resto << " horas." << endl;
    }
    else {
        cout << "Felicidades, usted completo su jornada de 8 horas :D" << endl;
    }

    return 0;
}

float convercion(float t, int &horasextra) { //las horas extra enlasadas hace que sea mas facil
    float horas = t / 60;
    if (horas > 8) {
        horasextra = horas - 8;
    } else {
        horasextra = 0;
    }
    return horas;
}
