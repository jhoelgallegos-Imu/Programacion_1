// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 3
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void LeerArchivo(const char nombreArchivo[30]) {
    ifstream archivo(nombreArchivo);
    char linea[100];
    cout << "\n=== CONTENIDO DEL ARCHIVO ===\n\n";
    while (archivo.getline(linea, 100)) {
        cout << linea << endl;
    }
    archivo.close();
    cout << "\n=== FIN DEL ARCHIVO ===" << endl;
}

int main() {
    vector<Estudiante> estudiantes;
    int opcion;
    do {
        cout << "==============================================================" << endl
             << "\tSISTEMA DE REGISTRO DE ESTUDIANTES" << endl
             << "==============================================================" << endl;
        cout << "Seleccione una opcion:" << endl
             << " 0) Salir del programa" << endl
             << " 1) Ingresar estudiante" << endl
             << " 2) Leer archivo guardado" << endl;
        cin >> opcion;
        cin.ignore();
        if (opcion == 1) {
            system("cls");
            Estudiante est;
            cout << "==============================================================" << endl
                 << "\tINGRESO DE NUEVO ESTUDIANTE" << endl
                 << "==============================================================" << endl;
            cout << "Nombre del estudiante: ";
            cin.getline(est.nombre, 50);
            cout << "Edad: ";
            cin >> est.edad;
            cout << "Promedio de calificaciones: ";
            cin >> est.promedio;
            ofstream archivo("ESTUDIANTES.txt", ios::app);
            archivo << "Nombre: " << est.nombre 
                    << " | Edad: " << est.edad 
                    << " | Promedio: " << est.promedio << endl;
            archivo.close();
            cout << "\nEstudiante guardado correctamente en el archivo." << endl;
        }
        else if (opcion == 2) {
            system("cls");
            LeerArchivo("ESTUDIANTES.txt");
        }
        else if (opcion > 2 || opcion < 0) {
            cout << "Opción invalida, seleccione otra " << endl;
        }
        system("pause");
        system("cls");
    } while (opcion != 0); //para que se pueda hacer veces indeterminadas, o ver el progreso del archivo
    cout << "Cerrando programa, hasta la proxima :)" << endl;
    return 0;
}
