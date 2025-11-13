// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 4
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int Containador(const char nombreArchivo[30], const string &busqueda) {
    ifstream archivo(nombreArchivo);
    string linea;
    int contador = 0;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(busqueda);
        while (pos != string::npos) {
            contador++;
            pos = linea.find(busqueda, pos + busqueda.length());
        }
    }
    archivo.close();
    return contador;
}

int main() {
    char nombreArchivo[30] = "ESTUDIANTES.txt"; // use un archivo ya creado para que sea mas facil
    string busqueda;

    cout << "Ingrese la palabra o frase a buscar: ";
    getline(cin, busqueda);

    int apariciones = Containador(nombreArchivo, busqueda);

    cout << "La palabra o frase " << busqueda 
         << " aparece " << apariciones << " veces en el archivo." << endl;

    return 0;
}
