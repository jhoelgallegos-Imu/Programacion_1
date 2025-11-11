// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 1
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void leerArchivo(const char nombreArchivo[30]) { //esta funcion lee el archivo, con el cout se puede diferenciar de cuando empieza y acaba
    ifstream archivo(nombreArchivo);
    char linea[30];
    cout << "\n=== Contenido del archivo ===\n\n";
    while (archivo.getline(linea, 30)) {
        cout << linea << endl;
    }
    archivo.close();
    cout << "\n=== Fin del archivo ===" << endl;
}

int main() {
    ofstream datos;
    datos.open("Nombres.txt");
    datos << "\tNombres Ingresados:\n";
    int confirmation = 0, numero = 0;
    do {
        cout <<" Bienvenido al sistema de escritura de nombres en un archivo de txt\n"
        << " Quiere ingresar un nombre? 1) Si / 2) No : ";
        cin >> confirmation;
        cin.ignore();
        if (confirmation == 1) {
            numero++;
            char NombreX[30];
            cout << "Escriba un nombre de menos de 30 caracteres: ";
            cin.getline(NombreX, 30);
            datos << "\t Nombre " << numero << ": " << NombreX << endl;
        } else if (confirmation > 2 || confirmation < 1 ) {
            cout << "Numero no valido, favor de ingresar alguna opción valida" << endl;
            system("pause");
        } else {
            cout << "Cerrando programa de guardado de nombres . . . " << endl;
            system("pause");
        }
        system("cls");
    } while (confirmation != 2);
    datos.close();
    char nombreArchivo[30] = "Nombres.txt";
    leerArchivo(nombreArchivo);
    return 0;
}